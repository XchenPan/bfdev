/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * Copyright(c) 2022 John Sanpe <sanpeqf@gmail.com>
 */

#include <bfdev.h>
#include <bfdev/lru.h>
#include <bfdev/log2.h>
#include <export.h>

static __bfdev_always_inline struct bfdev_hlist_head *
lru_hash_slot(struct bfdev_lru_head *head, unsigned int tag)
{
    return head->taghash + (tag & head->nmask);
}

static __bfdev_always_inline bool
lru_unused_starving(struct bfdev_lru_head *head)
{
    return bfdev_list_check_empty(&head->lru) &&
           bfdev_list_check_empty(&head->freed);
}

static struct bfdev_lru_node *
lru_find_change(struct bfdev_lru_head *head, unsigned int tag, bool change)
{
    struct bfdev_lru_node *walk;

    bfdev_hlist_for_each_entry(walk, lru_hash_slot(head, tag), hash) {
        if (walk->tag != tag)
            continue;
        if (!walk->uncommitted || change)
            return walk;
        break;
    }

    return NULL;
}

static struct bfdev_lru_node *
lru_unused_change(struct bfdev_lru_head *head, unsigned int tag)
{
    struct bfdev_lru_node *node;

    if (!bfdev_list_check_empty(&head->freed))
        node = bfdev_list_first_entry(&head->freed, struct bfdev_lru_node, list);
    else if (!bfdev_list_check_empty(&head->lru))
        node = bfdev_list_last_entry(&head->lru, struct bfdev_lru_node, list);
    else
        return NULL;

    if (!bfdev_hlist_check_unhashed(&node->hash))
        bfdev_hlist_del(&node->hash);

    node->tag = tag;
    node->uncommitted = true;

    bfdev_list_move(&head->changing, &node->list);
    bfdev_hlist_head_add(lru_hash_slot(head, tag), &node->hash);

    return node;
}

struct bfdev_lru_node *
lru_find(struct bfdev_lru_head *head, unsigned int tag)
{
    return lru_find_change(head, tag, false);
}

export bool
bfdev_lru_check_used(struct bfdev_lru_head *head, unsigned int tag)
{
    struct bfdev_lru_node *node;
    node = lru_find_change(head, tag, true);
    return node && node->refcnt;
}

export struct bfdev_lru_node *
bfdev_lru_obtain(struct bfdev_lru_head *head, unsigned int tag,
                 unsigned long flags)
{
    struct bfdev_lru_node *node;

    if (bfdev_unlikely(lru_test_starving(head))) {
        head->starve++;
        return NULL;
    }

    node = lru_find_change(head, tag, true);
    if (!node) {
        head->misses++;
        if (!(flags & BFDEV_LRU_CHANGE))
            return NULL;

        lru_set_dirty(head);
        if (bfdev_unlikely(lru_unused_starving(head))) {
            lru_set_starving(head);
            return NULL;
        }

        if (bfdev_unlikely(head->pending >= head->maxpend))
            return NULL;

        node = lru_unused_change(head, tag);
        lru_clr_starving(head);
        head->pending++;
        head->used++;

        return node;
    }

    head->hits++;
    if (node->uncommitted) {
        if (!(flags & BFDEV_LRU_UNCOMMITTED))
            return NULL;
        node->refcnt++;
    } else {
        if (!node->refcnt++)
            head->used++;
        bfdev_list_move(&head->using, &node->list);
    }

    return node;
}

export unsigned int
bfdev_lru_put(struct bfdev_lru_head *head, struct bfdev_lru_node *node)
{
    if (!--node->refcnt) {
        lru_clr_starving(head);
        bfdev_list_move(&head->lru, &node->list);
        head->used--;
    }

    return node->refcnt;
}

export int
bfdev_lru_del(struct bfdev_lru_head *head, struct bfdev_lru_node *node)
{
    if (node->refcnt)
        return -BFDEV_EBUSY;

    node->tag = BFDEV_LRU_FREE_TAG;
    bfdev_hlist_del_init(&node->hash);
    bfdev_list_move(&head->freed, &node->list);

    return -BFDEV_ENOERR;
}

export void
bfdev_lru_set(struct bfdev_lru_head *head, struct bfdev_lru_node *node,
              unsigned int tag)
{
    node->tag = tag;

    if (!bfdev_hlist_check_unhashed(&node->hash))
        bfdev_hlist_del(&node->hash);

    if (tag == BFDEV_LRU_FREE_TAG) {
        bfdev_hlist_node_init(&node->hash);
        bfdev_list_move(&head->freed, &node->list);
    } else {
        bfdev_hlist_head_add(lru_hash_slot(head, tag), &node->hash);
        bfdev_list_move(&head->lru, &node->list);
    }
}

export void
bfdev_lru_committed(struct bfdev_lru_head *head)
{
    struct bfdev_lru_node *node, *tmp;

    bfdev_list_for_each_entry_safe(node, tmp, &head->changing, list) {
        bfdev_list_move(&head->using, &node->list);
        node->uncommitted = false;
        head->changed++;
    };

    head->pending = 0;
}

export void
bfdev_lru_reset(struct bfdev_lru_head *head)
{
    unsigned int size = head->nmask + 1;
    unsigned int count;
    struct bfdev_lru_node *node;

    head->flags = 0;
    head->pending = 0;
    head->used = 0;
    head->hits = 0;
    head->misses = 0;
    head->starve = 0;

    bfdev_list_head_init(&head->lru);
    bfdev_list_head_init(&head->using);
    bfdev_list_head_init(&head->freed);
    bfdev_list_head_init(&head->changing);
    memset(head->taghash, 0, sizeof(*head->taghash) * size);

    for (count = 0; count < size; ++count) {
        node = head->nodes[count];
        memset(node, 0, sizeof(*node));

        node->index = count;
        node->tag = BFDEV_LRU_FREE_TAG;
        bfdev_list_add(&head->freed, &node->list);
    }
}

export struct bfdev_lru_head *
bfdev_lru_create(const struct bfdev_alloc *alloc,
                 unsigned int size, unsigned int maxpend)
{
    struct bfdev_lru_head *head;
    struct bfdev_lru_node *node;
    unsigned int count;

    size = bfdev_pow2_roundup(size);
    if (bfdev_unlikely(size < 2))
        return NULL;

    head = bfdev_zalloc(alloc, sizeof(*head));
    if (bfdev_unlikely(!head))
        return NULL;

    head->taghash = bfdev_zalloc_array(alloc, size, sizeof(*head->taghash));
    if (bfdev_unlikely(!head->taghash))
        goto free_head;

    head->nodes = bfdev_zalloc_array(alloc, size, sizeof(*head->nodes));
    if (bfdev_unlikely(!head->nodes))
        goto free_htable;

    head->alloc = alloc;
    head->nmask = size - 1;
    head->maxpend = maxpend;

    bfdev_list_head_init(&head->lru);
    bfdev_list_head_init(&head->using);
    bfdev_list_head_init(&head->freed);
    bfdev_list_head_init(&head->changing);

    for (count = 0; count < size; ++count) {
        node = bfdev_zalloc(alloc, sizeof(*node));
        if (bfdev_unlikely(!node))
            goto free_element;

        node->index = count;
        node->tag = BFDEV_LRU_FREE_TAG;

        bfdev_list_add(&head->freed, &node->list);
        head->nodes[count] = node;
    }

    return head;

free_element:
    while (count--) {
        node = head->nodes[count];
        bfdev_free(alloc, node);
    }
    bfdev_free(alloc, head->nodes);

free_htable:
    bfdev_free(alloc, head->taghash);

free_head:
    bfdev_free(alloc, head);
    return NULL;
}

export void
bfdev_lru_destroy(struct bfdev_lru_head *head)
{
    const struct bfdev_alloc *alloc;
    struct bfdev_lru_node *node;
    unsigned int count, size;

    alloc = head->alloc;
    size = head->nmask + 1;

    for (count = 0; count < size; ++count) {
        node = head->nodes[count];
        bfdev_free(alloc, node);
    }

    bfdev_free(alloc, head->nodes);
    bfdev_free(alloc, head->taghash);
    bfdev_free(alloc, head);
}
