/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * Copyright(c) 2023 John Sanpe <sanpeqf@gmail.com>
 */

#include <bfdev.h>
#include <bfdev/ctype.h>
#include <bfdev/ascii.h>
#include <export.h>

export const unsigned short
bfdev_ctype_table[256] = {
    [BFDEV_ASCII_NUL] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_CNTRL,
    [BFDEV_ASCII_SOH] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_CNTRL,
    [BFDEV_ASCII_STX] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_CNTRL,
    [BFDEV_ASCII_ETX] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_CNTRL,
    [BFDEV_ASCII_EOT] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_CNTRL,
    [BFDEV_ASCII_ENQ] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_CNTRL,
    [BFDEV_ASCII_ACK] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_CNTRL,
    [BFDEV_ASCII_BEL] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_CNTRL,
    [BFDEV_ASCII_BS ] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_CNTRL,
    [BFDEV_ASCII_HT ] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_CNTRL | BFDEV_CTYPE_SPACE,
    [BFDEV_ASCII_LF ] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_CNTRL | BFDEV_CTYPE_SPACE,
    [BFDEV_ASCII_VT ] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_CNTRL | BFDEV_CTYPE_SPACE | BFDEV_CTYPE_BLANK,
    [BFDEV_ASCII_FF ] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_CNTRL | BFDEV_CTYPE_SPACE,
    [BFDEV_ASCII_CR ] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_CNTRL | BFDEV_CTYPE_SPACE,
    [BFDEV_ASCII_SO ] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_CNTRL,
    [BFDEV_ASCII_SI ] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_CNTRL,
    [BFDEV_ASCII_DLE] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_CNTRL,
    [BFDEV_ASCII_DC1] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_CNTRL,
    [BFDEV_ASCII_DC2] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_CNTRL,
    [BFDEV_ASCII_DC3] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_CNTRL,
    [BFDEV_ASCII_DC4] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_CNTRL,
    [BFDEV_ASCII_NAK] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_CNTRL,
    [BFDEV_ASCII_SYN] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_CNTRL,
    [BFDEV_ASCII_ETB] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_CNTRL,
    [BFDEV_ASCII_CAN] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_CNTRL,
    [BFDEV_ASCII_EM ] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_CNTRL,
    [BFDEV_ASCII_SUB] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_CNTRL,
    [BFDEV_ASCII_ESC] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_CNTRL,
    [BFDEV_ASCII_FS ] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_CNTRL,
    [BFDEV_ASCII_GS ] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_CNTRL,
    [BFDEV_ASCII_RS ] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_CNTRL,
    [BFDEV_ASCII_US ] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_CNTRL,

    [' ' ] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_SPACE | BFDEV_CTYPE_HDSPA | BFDEV_CTYPE_BLANK,
    ['!' ] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_PUNCT,
    ['"' ] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_PUNCT,
    ['#' ] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_PUNCT,
    ['$' ] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_PUNCT,
    ['%' ] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_PUNCT,
    ['&' ] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_PUNCT,
    ['\''] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_PUNCT,
    ['(' ] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_PUNCT,
    [')' ] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_PUNCT,
    ['*' ] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_PUNCT,
    ['+' ] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_PUNCT,
    [',' ] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_PUNCT,
    ['-' ] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_PUNCT,
    ['.' ] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_PUNCT,
    ['/' ] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_PUNCT,

    ['0'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_DIGIT,
    ['1'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_DIGIT | BFDEV_CTYPE_HEXDG,
    ['2'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_DIGIT | BFDEV_CTYPE_HEXDG,
    ['3'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_DIGIT | BFDEV_CTYPE_HEXDG,
    ['4'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_DIGIT | BFDEV_CTYPE_HEXDG,
    ['5'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_DIGIT | BFDEV_CTYPE_HEXDG,
    ['6'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_DIGIT | BFDEV_CTYPE_HEXDG,
    ['7'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_DIGIT | BFDEV_CTYPE_HEXDG,
    ['8'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_DIGIT | BFDEV_CTYPE_HEXDG,
    ['9'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_DIGIT | BFDEV_CTYPE_HEXDG,

    [':'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_PUNCT,
    [';'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_PUNCT,
    ['<'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_PUNCT,
    ['='] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_PUNCT,
    ['>'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_PUNCT,
    ['?'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_PUNCT,
    ['@'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_PUNCT,

    ['A'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_UPPER | BFDEV_CTYPE_HEXDG,
    ['B'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_UPPER | BFDEV_CTYPE_HEXDG,
    ['C'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_UPPER | BFDEV_CTYPE_HEXDG,
    ['D'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_UPPER | BFDEV_CTYPE_HEXDG,
    ['E'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_UPPER | BFDEV_CTYPE_HEXDG,
    ['F'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_UPPER | BFDEV_CTYPE_HEXDG,
    ['G'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_UPPER,
    ['H'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_UPPER,
    ['I'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_UPPER,
    ['J'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_UPPER,
    ['K'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_UPPER,
    ['L'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_UPPER,
    ['M'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_UPPER,
    ['N'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_UPPER,
    ['O'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_UPPER,
    ['P'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_UPPER,
    ['Q'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_UPPER,
    ['R'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_UPPER,
    ['S'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_UPPER,
    ['T'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_UPPER,
    ['U'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_UPPER,
    ['V'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_UPPER,
    ['W'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_UPPER,
    ['X'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_UPPER,
    ['Y'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_UPPER,
    ['Z'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_UPPER,

    ['[' ] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_PUNCT,
    ['\\'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_PUNCT,
    [']' ] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_PUNCT,
    ['^' ] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_PUNCT,
    ['_' ] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_PUNCT,
    ['`' ] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_PUNCT,

    ['a'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_LOWER | BFDEV_CTYPE_HEXDG,
    ['b'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_LOWER | BFDEV_CTYPE_HEXDG,
    ['c'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_LOWER | BFDEV_CTYPE_HEXDG,
    ['d'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_LOWER | BFDEV_CTYPE_HEXDG,
    ['e'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_LOWER | BFDEV_CTYPE_HEXDG,
    ['f'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_LOWER | BFDEV_CTYPE_HEXDG,
    ['g'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_LOWER,
    ['h'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_LOWER,
    ['i'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_LOWER,
    ['j'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_LOWER,
    ['k'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_LOWER,
    ['l'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_LOWER,
    ['m'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_LOWER,
    ['n'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_LOWER,
    ['o'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_LOWER,
    ['p'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_LOWER,
    ['q'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_LOWER,
    ['r'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_LOWER,
    ['s'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_LOWER,
    ['t'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_LOWER,
    ['u'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_LOWER,
    ['v'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_LOWER,
    ['w'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_LOWER,
    ['x'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_LOWER,
    ['y'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_LOWER,
    ['z'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_LOWER,

    ['{'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_PUNCT,
    ['|'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_PUNCT,
    ['}'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_PUNCT,
    ['~'] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_PUNCT,
    [127] = BFDEV_CTYPE_ASCII | BFDEV_CTYPE_CNTRL,
    [128 ... 159] = 0,

    /* 160-175 */
    BFDEV_CTYPE_SPACE | BFDEV_CTYPE_HDSPA,
    BFDEV_CTYPE_PUNCT,
    BFDEV_CTYPE_PUNCT,
    BFDEV_CTYPE_PUNCT,
    BFDEV_CTYPE_PUNCT,
    BFDEV_CTYPE_PUNCT,
    BFDEV_CTYPE_PUNCT,
    BFDEV_CTYPE_PUNCT,
    BFDEV_CTYPE_PUNCT,
    BFDEV_CTYPE_PUNCT,
    BFDEV_CTYPE_PUNCT,
    BFDEV_CTYPE_PUNCT,
    BFDEV_CTYPE_PUNCT,
    BFDEV_CTYPE_PUNCT,
    BFDEV_CTYPE_PUNCT,
    BFDEV_CTYPE_PUNCT,

    /* 176-191 */
    BFDEV_CTYPE_PUNCT,
    BFDEV_CTYPE_PUNCT,
    BFDEV_CTYPE_PUNCT,
    BFDEV_CTYPE_PUNCT,
    BFDEV_CTYPE_PUNCT,
    BFDEV_CTYPE_PUNCT,
    BFDEV_CTYPE_PUNCT,
    BFDEV_CTYPE_PUNCT,
    BFDEV_CTYPE_PUNCT,
    BFDEV_CTYPE_PUNCT,
    BFDEV_CTYPE_PUNCT,
    BFDEV_CTYPE_PUNCT,
    BFDEV_CTYPE_PUNCT,
    BFDEV_CTYPE_PUNCT,
    BFDEV_CTYPE_PUNCT,
    BFDEV_CTYPE_PUNCT,

    /* 192-207 */
    BFDEV_CTYPE_UPPER,
    BFDEV_CTYPE_UPPER,
    BFDEV_CTYPE_UPPER,
    BFDEV_CTYPE_UPPER,
    BFDEV_CTYPE_UPPER,
    BFDEV_CTYPE_UPPER,
    BFDEV_CTYPE_UPPER,
    BFDEV_CTYPE_UPPER,
    BFDEV_CTYPE_UPPER,
    BFDEV_CTYPE_UPPER,
    BFDEV_CTYPE_UPPER,
    BFDEV_CTYPE_UPPER,
    BFDEV_CTYPE_UPPER,
    BFDEV_CTYPE_UPPER,
    BFDEV_CTYPE_UPPER,
    BFDEV_CTYPE_UPPER,

    /* 208-223 */
    BFDEV_CTYPE_UPPER,
    BFDEV_CTYPE_UPPER,
    BFDEV_CTYPE_UPPER,
    BFDEV_CTYPE_UPPER,
    BFDEV_CTYPE_UPPER,
    BFDEV_CTYPE_UPPER,
    BFDEV_CTYPE_UPPER,
    BFDEV_CTYPE_PUNCT,
    BFDEV_CTYPE_UPPER,
    BFDEV_CTYPE_UPPER,
    BFDEV_CTYPE_UPPER,
    BFDEV_CTYPE_UPPER,
    BFDEV_CTYPE_UPPER,
    BFDEV_CTYPE_UPPER,
    BFDEV_CTYPE_UPPER,
    BFDEV_CTYPE_LOWER,

    /* 224-239 */
    BFDEV_CTYPE_LOWER,
    BFDEV_CTYPE_LOWER,
    BFDEV_CTYPE_LOWER,
    BFDEV_CTYPE_LOWER,
    BFDEV_CTYPE_LOWER,
    BFDEV_CTYPE_LOWER,
    BFDEV_CTYPE_LOWER,
    BFDEV_CTYPE_LOWER,
    BFDEV_CTYPE_LOWER,
    BFDEV_CTYPE_LOWER,
    BFDEV_CTYPE_LOWER,
    BFDEV_CTYPE_LOWER,
    BFDEV_CTYPE_LOWER,
    BFDEV_CTYPE_LOWER,
    BFDEV_CTYPE_LOWER,
    BFDEV_CTYPE_LOWER,

    /* 240-255 */
    BFDEV_CTYPE_LOWER,
    BFDEV_CTYPE_LOWER,
    BFDEV_CTYPE_LOWER,
    BFDEV_CTYPE_LOWER,
    BFDEV_CTYPE_LOWER,
    BFDEV_CTYPE_LOWER,
    BFDEV_CTYPE_LOWER,
    BFDEV_CTYPE_PUNCT,
    BFDEV_CTYPE_LOWER,
    BFDEV_CTYPE_LOWER,
    BFDEV_CTYPE_LOWER,
    BFDEV_CTYPE_LOWER,
    BFDEV_CTYPE_LOWER,
    BFDEV_CTYPE_LOWER,
    BFDEV_CTYPE_LOWER,
    BFDEV_CTYPE_LOWER,
};
