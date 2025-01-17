/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * Copyright(c) 2023 John Sanpe <sanpeqf@gmail.com>
 */

#include <bfdev/popcount.h>
#include <export.h>

export const uint8_t bfdev_popcount_table[256] = {
    [0x00] = 0, [0x01] = 1, [0x02] = 1, [0x03] = 2,
    [0x04] = 1, [0x05] = 2, [0x06] = 2, [0x07] = 3,
    [0x08] = 1, [0x09] = 2, [0x0a] = 2, [0x0b] = 3,
    [0x0c] = 2, [0x0d] = 3, [0x0e] = 3, [0x0f] = 4,
    [0x10] = 1, [0x11] = 2, [0x12] = 2, [0x13] = 3,
    [0x14] = 2, [0x15] = 3, [0x16] = 3, [0x17] = 4,
    [0x18] = 2, [0x19] = 3, [0x1a] = 3, [0x1b] = 4,
    [0x1c] = 3, [0x1d] = 4, [0x1e] = 4, [0x1f] = 5,
    [0x20] = 1, [0x21] = 2, [0x22] = 2, [0x23] = 3,
    [0x24] = 2, [0x25] = 3, [0x26] = 3, [0x27] = 4,
    [0x28] = 2, [0x29] = 3, [0x2a] = 3, [0x2b] = 4,
    [0x2c] = 3, [0x2d] = 4, [0x2e] = 4, [0x2f] = 5,
    [0x30] = 2, [0x31] = 3, [0x32] = 3, [0x33] = 4,
    [0x34] = 3, [0x35] = 4, [0x36] = 4, [0x37] = 5,
    [0x38] = 3, [0x39] = 4, [0x3a] = 4, [0x3b] = 5,
    [0x3c] = 4, [0x3d] = 5, [0x3e] = 5, [0x3f] = 6,
    [0x40] = 1, [0x41] = 2, [0x42] = 2, [0x43] = 3,
    [0x44] = 2, [0x45] = 3, [0x46] = 3, [0x47] = 4,
    [0x48] = 2, [0x49] = 3, [0x4a] = 3, [0x4b] = 4,
    [0x4c] = 3, [0x4d] = 4, [0x4e] = 4, [0x4f] = 5,
    [0x50] = 2, [0x51] = 3, [0x52] = 3, [0x53] = 4,
    [0x54] = 3, [0x55] = 4, [0x56] = 4, [0x57] = 5,
    [0x58] = 3, [0x59] = 4, [0x5a] = 4, [0x5b] = 5,
    [0x5c] = 4, [0x5d] = 5, [0x5e] = 5, [0x5f] = 6,
    [0x60] = 2, [0x61] = 3, [0x62] = 3, [0x63] = 4,
    [0x64] = 3, [0x65] = 4, [0x66] = 4, [0x67] = 5,
    [0x68] = 3, [0x69] = 4, [0x6a] = 4, [0x6b] = 5,
    [0x6c] = 4, [0x6d] = 5, [0x6e] = 5, [0x6f] = 6,
    [0x70] = 3, [0x71] = 4, [0x72] = 4, [0x73] = 5,
    [0x74] = 4, [0x75] = 5, [0x76] = 5, [0x77] = 6,
    [0x78] = 4, [0x79] = 5, [0x7a] = 5, [0x7b] = 6,
    [0x7c] = 5, [0x7d] = 6, [0x7e] = 6, [0x7f] = 7,
    [0x80] = 1, [0x81] = 2, [0x82] = 2, [0x83] = 3,
    [0x84] = 2, [0x85] = 3, [0x86] = 3, [0x87] = 4,
    [0x88] = 2, [0x89] = 3, [0x8a] = 3, [0x8b] = 4,
    [0x8c] = 3, [0x8d] = 4, [0x8e] = 4, [0x8f] = 5,
    [0x90] = 2, [0x91] = 3, [0x92] = 3, [0x93] = 4,
    [0x94] = 3, [0x95] = 4, [0x96] = 4, [0x97] = 5,
    [0x98] = 3, [0x99] = 4, [0x9a] = 4, [0x9b] = 5,
    [0x9c] = 4, [0x9d] = 5, [0x9e] = 5, [0x9f] = 6,
    [0xa0] = 2, [0xa1] = 3, [0xa2] = 3, [0xa3] = 4,
    [0xa4] = 3, [0xa5] = 4, [0xa6] = 4, [0xa7] = 5,
    [0xa8] = 3, [0xa9] = 4, [0xaa] = 4, [0xab] = 5,
    [0xac] = 4, [0xad] = 5, [0xae] = 5, [0xaf] = 6,
    [0xb0] = 3, [0xb1] = 4, [0xb2] = 4, [0xb3] = 5,
    [0xb4] = 4, [0xb5] = 5, [0xb6] = 5, [0xb7] = 6,
    [0xb8] = 4, [0xb9] = 5, [0xba] = 5, [0xbb] = 6,
    [0xbc] = 5, [0xbd] = 6, [0xbe] = 6, [0xbf] = 7,
    [0xc0] = 2, [0xc1] = 3, [0xc2] = 3, [0xc3] = 4,
    [0xc4] = 3, [0xc5] = 4, [0xc6] = 4, [0xc7] = 5,
    [0xc8] = 3, [0xc9] = 4, [0xca] = 4, [0xcb] = 5,
    [0xcc] = 4, [0xcd] = 5, [0xce] = 5, [0xcf] = 6,
    [0xd0] = 3, [0xd1] = 4, [0xd2] = 4, [0xd3] = 5,
    [0xd4] = 4, [0xd5] = 5, [0xd6] = 5, [0xd7] = 6,
    [0xd8] = 4, [0xd9] = 5, [0xda] = 5, [0xdb] = 6,
    [0xdc] = 5, [0xdd] = 6, [0xde] = 6, [0xdf] = 7,
    [0xe0] = 3, [0xe1] = 4, [0xe2] = 4, [0xe3] = 5,
    [0xe4] = 4, [0xe5] = 5, [0xe6] = 5, [0xe7] = 6,
    [0xe8] = 4, [0xe9] = 5, [0xea] = 5, [0xeb] = 6,
    [0xec] = 5, [0xed] = 6, [0xee] = 6, [0xef] = 7,
    [0xf0] = 4, [0xf1] = 5, [0xf2] = 5, [0xf3] = 6,
    [0xf4] = 5, [0xf5] = 6, [0xf6] = 6, [0xf7] = 7,
    [0xf8] = 5, [0xf9] = 6, [0xfa] = 6, [0xfb] = 7,
    [0xfc] = 6, [0xfd] = 7, [0xfe] = 7, [0xff] = 8,
};

export const uint8_t bfdev_popparity_table[256] = {
    [0x00] = 0, [0x01] = 1, [0x02] = 1, [0x03] = 0,
    [0x04] = 1, [0x05] = 0, [0x06] = 0, [0x07] = 1,
    [0x08] = 1, [0x09] = 0, [0x0a] = 0, [0x0b] = 1,
    [0x0c] = 0, [0x0d] = 1, [0x0e] = 1, [0x0f] = 0,
    [0x10] = 1, [0x11] = 0, [0x12] = 0, [0x13] = 1,
    [0x14] = 0, [0x15] = 1, [0x16] = 1, [0x17] = 0,
    [0x18] = 0, [0x19] = 1, [0x1a] = 1, [0x1b] = 0,
    [0x1c] = 1, [0x1d] = 0, [0x1e] = 0, [0x1f] = 1,
    [0x20] = 1, [0x21] = 0, [0x22] = 0, [0x23] = 1,
    [0x24] = 0, [0x25] = 1, [0x26] = 1, [0x27] = 0,
    [0x28] = 0, [0x29] = 1, [0x2a] = 1, [0x2b] = 0,
    [0x2c] = 1, [0x2d] = 0, [0x2e] = 0, [0x2f] = 1,
    [0x30] = 0, [0x31] = 1, [0x32] = 1, [0x33] = 0,
    [0x34] = 1, [0x35] = 0, [0x36] = 0, [0x37] = 1,
    [0x38] = 1, [0x39] = 0, [0x3a] = 0, [0x3b] = 1,
    [0x3c] = 0, [0x3d] = 1, [0x3e] = 1, [0x3f] = 0,
    [0x40] = 1, [0x41] = 0, [0x42] = 0, [0x43] = 1,
    [0x44] = 0, [0x45] = 1, [0x46] = 1, [0x47] = 0,
    [0x48] = 0, [0x49] = 1, [0x4a] = 1, [0x4b] = 0,
    [0x4c] = 1, [0x4d] = 0, [0x4e] = 0, [0x4f] = 1,
    [0x50] = 0, [0x51] = 1, [0x52] = 1, [0x53] = 0,
    [0x54] = 1, [0x55] = 0, [0x56] = 0, [0x57] = 1,
    [0x58] = 1, [0x59] = 0, [0x5a] = 0, [0x5b] = 1,
    [0x5c] = 0, [0x5d] = 1, [0x5e] = 1, [0x5f] = 0,
    [0x60] = 0, [0x61] = 1, [0x62] = 1, [0x63] = 0,
    [0x64] = 1, [0x65] = 0, [0x66] = 0, [0x67] = 1,
    [0x68] = 1, [0x69] = 0, [0x6a] = 0, [0x6b] = 1,
    [0x6c] = 0, [0x6d] = 1, [0x6e] = 1, [0x6f] = 0,
    [0x70] = 1, [0x71] = 0, [0x72] = 0, [0x73] = 1,
    [0x74] = 0, [0x75] = 1, [0x76] = 1, [0x77] = 0,
    [0x78] = 0, [0x79] = 1, [0x7a] = 1, [0x7b] = 0,
    [0x7c] = 1, [0x7d] = 0, [0x7e] = 0, [0x7f] = 1,
    [0x80] = 1, [0x81] = 0, [0x82] = 0, [0x83] = 1,
    [0x84] = 0, [0x85] = 1, [0x86] = 1, [0x87] = 0,
    [0x88] = 0, [0x89] = 1, [0x8a] = 1, [0x8b] = 0,
    [0x8c] = 1, [0x8d] = 0, [0x8e] = 0, [0x8f] = 1,
    [0x90] = 0, [0x91] = 1, [0x92] = 1, [0x93] = 0,
    [0x94] = 1, [0x95] = 0, [0x96] = 0, [0x97] = 1,
    [0x98] = 1, [0x99] = 0, [0x9a] = 0, [0x9b] = 1,
    [0x9c] = 0, [0x9d] = 1, [0x9e] = 1, [0x9f] = 0,
    [0xa0] = 0, [0xa1] = 1, [0xa2] = 1, [0xa3] = 0,
    [0xa4] = 1, [0xa5] = 0, [0xa6] = 0, [0xa7] = 1,
    [0xa8] = 1, [0xa9] = 0, [0xaa] = 0, [0xab] = 1,
    [0xac] = 0, [0xad] = 1, [0xae] = 1, [0xaf] = 0,
    [0xb0] = 1, [0xb1] = 0, [0xb2] = 0, [0xb3] = 1,
    [0xb4] = 0, [0xb5] = 1, [0xb6] = 1, [0xb7] = 0,
    [0xb8] = 0, [0xb9] = 1, [0xba] = 1, [0xbb] = 0,
    [0xbc] = 1, [0xbd] = 0, [0xbe] = 0, [0xbf] = 1,
    [0xc0] = 0, [0xc1] = 1, [0xc2] = 1, [0xc3] = 0,
    [0xc4] = 1, [0xc5] = 0, [0xc6] = 0, [0xc7] = 1,
    [0xc8] = 1, [0xc9] = 0, [0xca] = 0, [0xcb] = 1,
    [0xcc] = 0, [0xcd] = 1, [0xce] = 1, [0xcf] = 0,
    [0xd0] = 1, [0xd1] = 0, [0xd2] = 0, [0xd3] = 1,
    [0xd4] = 0, [0xd5] = 1, [0xd6] = 1, [0xd7] = 0,
    [0xd8] = 0, [0xd9] = 1, [0xda] = 1, [0xdb] = 0,
    [0xdc] = 1, [0xdd] = 0, [0xde] = 0, [0xdf] = 1,
    [0xe0] = 1, [0xe1] = 0, [0xe2] = 0, [0xe3] = 1,
    [0xe4] = 0, [0xe5] = 1, [0xe6] = 1, [0xe7] = 0,
    [0xe8] = 0, [0xe9] = 1, [0xea] = 1, [0xeb] = 0,
    [0xec] = 1, [0xed] = 0, [0xee] = 0, [0xef] = 1,
    [0xf0] = 0, [0xf1] = 1, [0xf2] = 1, [0xf3] = 0,
    [0xf4] = 1, [0xf5] = 0, [0xf6] = 0, [0xf7] = 1,
    [0xf8] = 1, [0xf9] = 0, [0xfa] = 0, [0xfb] = 1,
    [0xfc] = 0, [0xfd] = 1, [0xfe] = 1, [0xff] = 0,
};
