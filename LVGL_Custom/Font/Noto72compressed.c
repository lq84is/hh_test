/*******************************************************************************
 * Size: 72 px
 * Bpp: 2
 * Opts: 
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef NOTO72COMPRESSED
#define NOTO72COMPRESSED 1
#endif

#if NOTO72COMPRESSED

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+002D "-" */
    0x2b, 0xff, 0x8a, 0x5, 0xff, 0xe3, 0x7, 0xff,
    0xfc,

    /* U+002E "." */
    0xf, 0xfe, 0x5, 0xf8, 0x36, 0x86, 0xd1, 0xf,
    0xa3, 0xf, 0xe4, 0x3f, 0xf8, 0xe8, 0x7f, 0x41,
    0xf4, 0x8, 0x39, 0x40, 0x7a, 0xb8, 0x0,

    /* U+0030 "0" */
    0xf, 0xfe, 0x3, 0x7f, 0xa8, 0x87, 0xff, 0x2a,
    0xe4, 0x3c, 0xab, 0x83, 0xff, 0x8c, 0xe8, 0x7f,
    0xf0, 0x5d, 0xf, 0xfe, 0x1d, 0x3, 0xff, 0x8b,
    0x40, 0xff, 0xe0, 0xc8, 0x7f, 0xf1, 0xd8, 0x3f,
    0xe9, 0xf, 0xcd, 0x48, 0x7e, 0x50, 0x7f, 0x28,
    0x3c, 0xfa, 0x5a, 0xf2, 0x1e, 0x83, 0xfa, 0xf,
    0x50, 0x3f, 0xa8, 0x1e, 0x83, 0xe4, 0x3c, 0xa0,
    0xff, 0x94, 0x1c, 0xa0, 0xf4, 0x1e, 0x83, 0xff,
    0x83, 0x7, 0xb0, 0xff, 0xe0, 0x41, 0xff, 0xc3,
    0x83, 0x90, 0xe8, 0x3c, 0x87, 0xff, 0xd, 0xf,
    0x41, 0x90, 0xe4, 0x3f, 0xf8, 0xb0, 0x72, 0x1f,
    0xe8, 0x3f, 0xf8, 0xa8, 0x7f, 0x21, 0xff, 0xd3,
    0x41, 0x87, 0x21, 0xff, 0xc7, 0x43, 0xb0, 0xff,
    0xe8, 0x61, 0xc8, 0x10, 0xec, 0x3f, 0xfd, 0x48,
    0x7f, 0xf0, 0x90, 0xff, 0xe7, 0x21, 0xff, 0xd7,
    0x43, 0xff, 0xf1, 0x87, 0xff, 0xfc, 0x3f, 0xff,
    0xe1, 0xff, 0xff, 0xf, 0xff, 0xf8, 0x7f, 0xf0,
    0xb4, 0x3f, 0xff, 0xe2, 0x1f, 0xfc, 0x74, 0x3c,
    0x88, 0x7f, 0xf7, 0x30, 0xff, 0xe3, 0xe1, 0xfb,
    0xe, 0x43, 0xff, 0x8e, 0x87, 0x20, 0x43, 0xff,
    0xa7, 0x87, 0xf2, 0x1f, 0xfc, 0x54, 0x3c, 0x84,
    0x87, 0x61, 0xff, 0xc5, 0xc3, 0xfd, 0x7, 0x21,
    0xff, 0xc5, 0x43, 0x90, 0xff, 0xa0, 0xff, 0xe1,
    0xc1, 0xe8, 0x3a, 0xe, 0x43, 0xff, 0x86, 0x87,
    0x21, 0xe4, 0x3d, 0x87, 0xff, 0x7, 0xf, 0x41,
    0xf4, 0x1e, 0xc3, 0xfe, 0xc3, 0xc8, 0x7e, 0x50,
    0x7b, 0x90, 0xe6, 0xc3, 0xe8, 0x3f, 0xa0, 0xf9,
    0xbf, 0xa4, 0x3e, 0x83, 0xfe, 0xc3, 0xff, 0x93,
    0x21, 0xff, 0xc0, 0xc3, 0xff, 0x8f, 0x21, 0xff,
    0xc2, 0xe0, 0xff, 0xe1, 0xba, 0x1f, 0xfc, 0x47,
    0x83, 0xfe, 0x78, 0x3f, 0xf9, 0xf, 0xd5, 0xef,
    0x41, 0xff, 0x0,

    /* U+0031 "1" */
    0xf, 0xfe, 0xb, 0xfd, 0x7, 0xff, 0x2, 0x81,
    0xff, 0xc5, 0xd0, 0xff, 0xe2, 0x38, 0x7f, 0xf1,
    0x68, 0x1f, 0xfc, 0x59, 0xf, 0xfe, 0x2e, 0x87,
    0xff, 0x11, 0xc3, 0xcc, 0x1f, 0xd4, 0xf, 0x30,
    0x7f, 0x68, 0x7a, 0x86, 0x1e, 0x70, 0xfa, 0x43,
    0xf9, 0xf, 0xb4, 0x3f, 0xec, 0x33, 0x87, 0xff,
    0xa, 0x5, 0x3, 0xff, 0x86, 0xa9, 0xf, 0xfe,
    0x2c, 0x87, 0xff, 0xfc, 0x3f, 0xff, 0xe1, 0xff,
    0xff, 0xf, 0xff, 0xf8, 0x7f, 0xff, 0xc3, 0xff,
    0xfe, 0x1f, 0xff, 0xf0, 0xff, 0xff, 0x87, 0xff,
    0xfc, 0x3f, 0xfb, 0x80,

    /* U+0032 "2" */
    0xf, 0xf9, 0xbf, 0xe9, 0xf, 0xfe, 0x4b, 0xe9,
    0xf, 0x9b, 0xd0, 0x7f, 0xf1, 0x1e, 0xf, 0xfe,
    0x1b, 0xa1, 0xff, 0xc0, 0x78, 0x3f, 0xf8, 0xf6,
    0x1f, 0xea, 0x7, 0xff, 0x2f, 0xf, 0x9d, 0xf,
    0xe5, 0x56, 0x43, 0xfb, 0xf, 0x61, 0xf9, 0xf5,
    0x17, 0x5c, 0x1f, 0xa0, 0xe8, 0x3c, 0xf0, 0x7f,
    0x9d, 0xf, 0x21, 0xec, 0x37, 0x7, 0xff, 0xa,
    0xf, 0x90, 0xf6, 0x58, 0x7f, 0xf1, 0x70, 0xf4,
    0x1f, 0x68, 0x7f, 0xf1, 0xd0, 0xff, 0xeb, 0x61,
    0xff, 0xd6, 0x43, 0xc8, 0x7f, 0xff, 0xc3, 0xff,
    0xda, 0x87, 0x90, 0xff, 0xe7, 0xe1, 0xff, 0xd6,
    0x43, 0x90, 0xff, 0xeb, 0x61, 0xff, 0xcf, 0x83,
    0xc8, 0x7f, 0xf3, 0xd0, 0xe4, 0x3f, 0xf9, 0xf0,
    0x7a, 0xf, 0xfe, 0x72, 0x83, 0x90, 0xff, 0xe7,
    0xc1, 0xe8, 0x3f, 0xf9, 0xd8, 0x7b, 0xf, 0xfe,
    0x74, 0x1e, 0x43, 0xff, 0x9d, 0x21, 0xcc, 0x1f,
    0xfc, 0xd9, 0xf, 0x41, 0xff, 0xcd, 0x90, 0xf6,
    0x1f, 0xfc, 0xd5, 0x7, 0xb0, 0xff, 0xe6, 0xb0,
    0x7b, 0xf, 0xfe, 0x6b, 0x7, 0xa0, 0xff, 0xe6,
    0xb0, 0x7a, 0x43, 0xff, 0x98, 0xc1, 0xe9, 0xf,
    0xfe, 0x63, 0x7, 0xa4, 0x3f, 0xf9, 0x8c, 0x1e,
    0x90, 0xff, 0xe6, 0x30, 0x7b, 0x43, 0xff, 0x98,
    0xc1, 0xec, 0x3f, 0xf9, 0xac, 0x1e, 0xc3, 0xff,
    0x9a, 0xc1, 0xec, 0x3f, 0xf9, 0xac, 0x1e, 0xc3,
    0xff, 0x9a, 0xc1, 0xec, 0x3f, 0xf9, 0xac, 0x1e,
    0xc3, 0xff, 0x9a, 0xc1, 0xec, 0x3f, 0xf9, 0xac,
    0x1e, 0xc3, 0xff, 0x9a, 0xc1, 0xf7, 0xff, 0xf3,
    0x5c, 0x3f, 0xff, 0xe1, 0xff, 0xff, 0xf, 0xfe,
    0x60,

    /* U+0033 "3" */
    0xf, 0xf3, 0x4f, 0xfa, 0x88, 0x7f, 0xf1, 0xdf,
    0x4a, 0xf, 0x95, 0x79, 0xf, 0xfe, 0x15, 0xc1,
    0xff, 0xc5, 0xb4, 0x3f, 0xd6, 0x87, 0xff, 0x26,
    0x43, 0xe7, 0x43, 0xff, 0x99, 0x21, 0xe8, 0x3f,
    0xca, 0xae, 0x43, 0xfa, 0x43, 0x90, 0xf9, 0xf5,
    0x17, 0xaf, 0x21, 0xf4, 0x1d, 0x7, 0x5c, 0x1f,
    0xfc, 0xa, 0x7, 0xc8, 0x76, 0x7, 0x43, 0xff,
    0x86, 0xc1, 0xe8, 0x3d, 0x70, 0x7f, 0xf1, 0x90,
    0xff, 0xe0, 0xa1, 0xff, 0xc9, 0x83, 0xc8, 0x7f,
    0xf3, 0xd0, 0xff, 0xff, 0x87, 0xff, 0xd1, 0xf,
    0x21, 0xff, 0xcf, 0xc3, 0xff, 0xac, 0x87, 0x21,
    0xff, 0xcf, 0xc3, 0xd0, 0x7f, 0xf3, 0xa0, 0xf2,
    0x1f, 0xfc, 0xed, 0xf, 0x41, 0xff, 0xcb, 0x6c,
    0x3c, 0xe1, 0xff, 0xc1, 0x5f, 0xd7, 0xa4, 0x3d,
    0x40, 0xff, 0xe1, 0x57, 0xe4, 0x3f, 0x3a, 0x1f,
    0xfd, 0x16, 0xe0, 0xff, 0xe9, 0xba, 0x1f, 0xfd,
    0x56, 0xf2, 0x1f, 0xfd, 0x6b, 0x43, 0xff, 0x83,
    0xff, 0xd4, 0x43, 0xfa, 0x43, 0xff, 0x92, 0xab,
    0xc8, 0x7d, 0x21, 0xff, 0xcd, 0xb4, 0x3d, 0x7,
    0xff, 0x3e, 0x43, 0xd8, 0x7f, 0xf3, 0xe0, 0xf9,
    0xf, 0xfe, 0x7c, 0x1e, 0xc3, 0xff, 0x9e, 0x87,
    0x90, 0xff, 0xe8, 0x21, 0xff, 0xff, 0xf, 0xff,
    0xa2, 0x1f, 0xfd, 0xc4, 0x3f, 0xf9, 0xe8, 0x7f,
    0xf5, 0xa0, 0xf4, 0x1f, 0xfc, 0xe8, 0x3f, 0xa8,
    0x1f, 0xfc, 0xa9, 0xf, 0x40, 0x57, 0x90, 0xff,
    0xe2, 0xba, 0x1e, 0x50, 0x7a, 0xf4, 0xa0, 0xfe,
    0x6e, 0xf, 0xd0, 0x7f, 0x9a, 0x7f, 0xf4, 0x87,
    0xf6, 0x1f, 0xfd, 0x5c, 0x39, 0xf, 0xfe, 0x73,
    0x87, 0xad, 0xf, 0xfe, 0x53, 0xc1, 0xfd, 0x72,
    0x1f, 0xfc, 0x46, 0xe0, 0xff, 0xe0, 0xb7, 0xea,
    0xfe, 0xfa, 0x43, 0xfe,

    /* U+0034 "4" */
    0xf, 0xfe, 0x6d, 0x78, 0x3f, 0xfa, 0x9a, 0xfc,
    0x1f, 0xfd, 0x28, 0x3f, 0xfb, 0x2a, 0xf, 0xfe,
    0xcc, 0x1f, 0xfd, 0x9c, 0x3f, 0xfb, 0x28, 0x7f,
    0xf6, 0xa0, 0xc8, 0x7f, 0xf5, 0x30, 0xc8, 0x7f,
    0xf5, 0x20, 0xe8, 0x3f, 0xfa, 0x6a, 0xc, 0x87,
    0xff, 0x52, 0xe, 0x83, 0xff, 0xa7, 0x7, 0x40,
    0x43, 0xff, 0xa0, 0xa0, 0xca, 0xf, 0xfe, 0x9c,
    0x1d, 0x7, 0xff, 0x4e, 0xe, 0x83, 0xff, 0xa6,
    0xa0, 0xca, 0xf, 0xfe, 0x9c, 0x1d, 0x7, 0xff,
    0x4f, 0xe, 0xc3, 0xff, 0xa7, 0x7, 0x21, 0xff,
    0xd4, 0x43, 0xa0, 0xff, 0xe9, 0xe1, 0xd8, 0x7f,
    0xf4, 0xe0, 0xe8, 0x3f, 0xfa, 0x6a, 0xc, 0xa0,
    0xff, 0xe9, 0xc1, 0xd0, 0x7f, 0xf4, 0xe0, 0xe8,
    0x3f, 0xfa, 0x6a, 0xc, 0xa0, 0xff, 0xe9, 0xc1,
    0xd0, 0x7f, 0xf4, 0xf0, 0xec, 0x3f, 0xfa, 0x68,
    0x72, 0x1f, 0xfd, 0x48, 0x3a, 0xf, 0xfe, 0x9e,
    0x1d, 0x87, 0xff, 0x4e, 0xe, 0x83, 0xff, 0xa6,
    0xa0, 0xca, 0xf, 0xfe, 0x9c, 0x1d, 0x7, 0xff,
    0x4d, 0xf, 0x7f, 0xff, 0x18, 0x3d, 0x7f, 0xc1,
    0xff, 0xff, 0xf, 0xff, 0xf8, 0x7c, 0xbf, 0xfc,
    0xc0, 0xf2, 0xfd, 0x35, 0xff, 0xcc, 0xf, 0x75,
    0xe4, 0x3f, 0xff, 0xe1, 0xff, 0xff, 0xf, 0xff,
    0xf8, 0x7f, 0xff, 0xc3, 0xff, 0xfe, 0x1f, 0xfc,
    0x30,

    /* U+0035 "5" */
    0x9, 0xff, 0xfe, 0x6a, 0x1f, 0xfd, 0xdc, 0x3f,
    0xff, 0xe1, 0xff, 0xd4, 0x5f, 0xfe, 0x40, 0x7e,
    0x43, 0xab, 0xff, 0x90, 0x87, 0xff, 0xfc, 0x3f,
    0xfb, 0x68, 0x7f, 0xfc, 0x50, 0xff, 0xed, 0xe1,
    0xff, 0xf1, 0xc3, 0xff, 0xb6, 0x87, 0xff, 0xc5,
    0xf, 0xff, 0x12, 0x1f, 0xfc, 0xeb, 0xfd, 0x7f,
    0x48, 0x7f, 0xf1, 0xd0, 0xff, 0xe0, 0x37, 0x7,
    0xff, 0x55, 0xe0, 0xff, 0xea, 0xba, 0x1f, 0x21,
    0xff, 0xcd, 0x90, 0xf5, 0x84, 0xd3, 0xfe, 0xa2,
    0x1f, 0xd0, 0x7e, 0xfa, 0x50, 0x7c, 0xab, 0x83,
    0xf6, 0x1f, 0xfc, 0xc7, 0x43, 0xe4, 0x3f, 0xf9,
    0xb2, 0x1e, 0x83, 0xff, 0x9d, 0x7, 0xc8, 0x7f,
    0xf3, 0xa0, 0xf6, 0x1f, 0xfc, 0xe4, 0x3c, 0x87,
    0xff, 0x3d, 0xf, 0xff, 0xbe, 0x1f, 0xff, 0x7c,
    0x3f, 0xfe, 0xe8, 0x72, 0x1f, 0xfd, 0x5c, 0x3f,
    0xf9, 0xd0, 0x79, 0xf, 0xfe, 0x72, 0x1f, 0xfd,
    0x4c, 0x3d, 0x1, 0x83, 0xff, 0x93, 0x87, 0xc8,
    0x4f, 0x90, 0xff, 0xe2, 0x58, 0x7d, 0x87, 0xd7,
    0xa5, 0x7, 0xe6, 0xd0, 0xfa, 0xf, 0xf9, 0xa7,
    0xfe, 0x90, 0xfc, 0xa0, 0xff, 0xe9, 0xd0, 0x3f,
    0xfa, 0x7a, 0x1e, 0x74, 0x3f, 0xf9, 0x36, 0x1f,
    0xeb, 0x90, 0xff, 0xe1, 0xde, 0x43, 0xff, 0x82,
    0xdf, 0x57, 0xf7, 0xc8, 0x7f, 0xf0, 0x0,

    /* U+0036 "6" */
    0xf, 0xfe, 0x33, 0x7f, 0xf4, 0x87, 0xff, 0x19,
    0xbd, 0x21, 0xfc, 0xc1, 0xff, 0xc4, 0x79, 0xf,
    0xfe, 0x95, 0x3, 0xff, 0xa6, 0xe8, 0x7f, 0xf4,
    0xd8, 0x3f, 0x95, 0x7e, 0xa9, 0xf, 0xfe, 0x3,
    0x7, 0xeb, 0xa2, 0x19, 0x6b, 0xf, 0xfa, 0xf,
    0xad, 0xf, 0xfe, 0x5e, 0x1e, 0x74, 0x3f, 0xf9,
    0x90, 0x79, 0x83, 0xff, 0x9c, 0x87, 0xa0, 0xff,
    0xe7, 0x41, 0xec, 0x3f, 0xf9, 0xe8, 0x74, 0x1f,
    0xfc, 0xf4, 0x3c, 0x87, 0xff, 0x3e, 0xe, 0x83,
    0xff, 0xac, 0x87, 0xff, 0x3d, 0xf, 0xfe, 0xb6,
    0x1c, 0x87, 0xff, 0x41, 0xe, 0xc3, 0xff, 0xac,
    0x87, 0xff, 0x3d, 0xf, 0xfe, 0xb, 0x7f, 0xa4,
    0x3f, 0xf8, 0xa8, 0x67, 0xd2, 0x1e, 0x6e, 0xf,
    0xec, 0x3f, 0xa8, 0x1f, 0xfc, 0x17, 0x83, 0xff,
    0x89, 0xa1, 0xff, 0xc4, 0x70, 0xf2, 0x1d, 0x98,
    0x7f, 0xf2, 0x30, 0xff, 0xe0, 0x61, 0xcd, 0xfd,
    0x21, 0xfb, 0xf, 0xf4, 0x1a, 0xe4, 0x39, 0xb8,
    0x3e, 0x83, 0xff, 0x83, 0xa1, 0xff, 0x30, 0x79,
    0xf, 0xfe, 0x6, 0x1f, 0xfc, 0x26, 0xf, 0x41,
    0xfe, 0xc3, 0xff, 0x88, 0x87, 0x90, 0xfe, 0x83,
    0xff, 0x8d, 0x7, 0xff, 0xd, 0xf, 0xfe, 0x32,
    0x1e, 0x43, 0xe4, 0x3f, 0xf9, 0xd8, 0x7d, 0x87,
    0xff, 0x21, 0xf, 0xfe, 0xe2, 0x21, 0xff, 0xce,
    0xc3, 0xff, 0x83, 0x87, 0xff, 0x23, 0xf, 0xb0,
    0xff, 0xea, 0x22, 0x1c, 0x87, 0xff, 0x5d, 0xf,
    0xfe, 0x3a, 0x1d, 0x81, 0xe, 0xc3, 0xff, 0xa1,
    0x7, 0x21, 0xff, 0xc6, 0x83, 0xc8, 0x48, 0x76,
    0x1f, 0xfc, 0x54, 0x39, 0xd, 0x7, 0xa0, 0xff,
    0xe1, 0xc1, 0xec, 0x39, 0xe, 0x50, 0x7f, 0xf0,
    0x64, 0x3c, 0x87, 0x41, 0xea, 0x7, 0xfd, 0x21,
    0xe8, 0x3e, 0x83, 0xce, 0x87, 0xd6, 0x87, 0x94,
    0x1f, 0x30, 0x7d, 0x7f, 0xc8, 0x7c, 0xc1, 0xfc,
    0xc1, 0xff, 0xc9, 0x60, 0xff, 0x98, 0x3f, 0xf8,
    0xec, 0x1f, 0xfc, 0x17, 0x43, 0xff, 0x89, 0xc1,
    0xff, 0xc4, 0xb8, 0x3f, 0xe7, 0xc1, 0xff, 0xc8,
    0x7e, 0xaf, 0x7a, 0xf, 0xf0,

    /* U+0037 "7" */
    0xff, 0xfe, 0xb4, 0x1f, 0xff, 0xf0, 0xff, 0xfa,
    0xaf, 0xff, 0x3c, 0x3e, 0xeb, 0xff, 0xa0, 0x1e,
    0x43, 0xff, 0x9f, 0x7, 0x41, 0xff, 0xcf, 0x43,
    0xc8, 0x7f, 0xf3, 0xe0, 0xe4, 0x3f, 0xf9, 0xe8,
    0x7a, 0xf, 0xfe, 0x7c, 0x1c, 0x87, 0xff, 0x3d,
    0xf, 0x41, 0xff, 0xcf, 0xc3, 0x90, 0xff, 0xe8,
    0x21, 0xd8, 0x7f, 0xf3, 0xe0, 0xf2, 0x1f, 0xfc,
    0xf4, 0x3a, 0xf, 0xfe, 0x7c, 0x1e, 0x43, 0xff,
    0x9e, 0x87, 0x41, 0xff, 0xcf, 0x83, 0xc8, 0x7f,
    0xf3, 0xd0, 0xe4, 0x3f, 0xf9, 0xe8, 0x7a, 0xf,
    0xfe, 0x7c, 0x1c, 0x87, 0xff, 0x3d, 0xf, 0x41,
    0xff, 0xcf, 0x83, 0xff, 0xaa, 0x87, 0xa0, 0xff,
    0xe7, 0xc1, 0xe4, 0x3f, 0xf9, 0xc8, 0x7a, 0xf,
    0xfe, 0x7e, 0x1e, 0x43, 0xff, 0x9e, 0x87, 0x21,
    0xff, 0xcf, 0x83, 0xd0, 0x7f, 0xf3, 0xd0, 0xe4,
    0x3f, 0xf9, 0xf0, 0x7a, 0xf, 0xfe, 0x7a, 0x1c,
    0x87, 0xff, 0x3e, 0xf, 0x41, 0xff, 0xcf, 0x43,
    0xff, 0xaa, 0x87, 0xa0, 0xff, 0xe7, 0xc1, 0xe4,
    0x3f, 0xf9, 0xc8, 0x7a, 0xf, 0xfe, 0x7c, 0x1e,
    0x43, 0xff, 0x9c, 0x87, 0x90, 0xff, 0xe7, 0xc1,
    0xe8, 0x3f, 0xfa, 0xa8, 0x7f, 0xf3, 0xe0, 0xf4,
    0x1f, 0xfc, 0xf4, 0x39, 0xf, 0xfe, 0x7c, 0x1e,
    0xc3, 0xff, 0x9e, 0x87, 0x90, 0xff, 0xe7, 0x41,
    0xe8, 0x3f, 0xf9, 0xe8, 0x79, 0xf, 0xfe, 0x74,
    0x1e, 0x83, 0xff, 0x9e, 0x87, 0x90, 0xff, 0xe4,
    0x0,

    /* U+0038 "8" */
    0xf, 0xfe, 0x3, 0x7f, 0xd2, 0x1f, 0xfc, 0x97,
    0xd2, 0x1f, 0x37, 0xa0, 0xff, 0xe2, 0x3c, 0x1f,
    0xfc, 0x37, 0x43, 0xff, 0x83, 0x40, 0xff, 0xe3,
    0xd8, 0x7f, 0xda, 0x1f, 0xfc, 0xac, 0x3f, 0xa0,
    0xfc, 0xdf, 0xd2, 0x1f, 0xb0, 0xf9, 0x41, 0xe7,
    0x90, 0xe6, 0xd0, 0xfa, 0xf, 0x41, 0xea, 0x7,
    0xfd, 0x40, 0xf2, 0x1c, 0x87, 0xa4, 0x3f, 0xf8,
    0x2c, 0x1e, 0x43, 0x61, 0xe4, 0x3f, 0xf8, 0x68,
    0x7b, 0xf, 0xf2, 0x1f, 0xfc, 0x54, 0x39, 0xc,
    0x87, 0x61, 0xff, 0xc5, 0xc3, 0xff, 0xc2, 0x87,
    0xff, 0x73, 0xf, 0xfe, 0x2e, 0x1c, 0x86, 0xc3,
    0x90, 0xff, 0xe2, 0xa1, 0xd8, 0x64, 0x3c, 0x87,
    0xff, 0xd, 0xf, 0x21, 0xc8, 0x74, 0x1f, 0xfc,
    0x38, 0x39, 0xf, 0x41, 0xec, 0x3f, 0xf8, 0x38,
    0x7a, 0xf, 0x90, 0xf6, 0x87, 0xf3, 0x87, 0xb0,
    0xfd, 0x21, 0xeb, 0x43, 0xd4, 0xf, 0x41, 0xfe,
    0x90, 0xfa, 0xd0, 0x3a, 0x1e, 0xd0, 0xff, 0xa4,
    0x3f, 0x5e, 0x83, 0xce, 0x1f, 0xfc, 0x2a, 0x7,
    0xff, 0x12, 0x81, 0xff, 0xc4, 0x74, 0x3f, 0xf8,
    0xe, 0x87, 0xff, 0x51, 0x83, 0xff, 0x8c, 0xe8,
    0x7f, 0xf0, 0x5d, 0xf, 0xfe, 0x1f, 0x7, 0xff,
    0x16, 0x81, 0xff, 0xc0, 0x70, 0xf9, 0xf9, 0xf,
    0xce, 0x87, 0xf3, 0x7, 0x9e, 0xa, 0xe0, 0xfd,
    0x21, 0xf3, 0x7, 0xa8, 0x1f, 0x3c, 0x1f, 0x48,
    0x7a, 0xf, 0x68, 0x7f, 0x9d, 0xf, 0x48, 0x6c,
    0x3d, 0x87, 0xff, 0xa, 0x43, 0xd0, 0x48, 0x7a,
    0xf, 0xfe, 0x24, 0x87, 0xa0, 0x41, 0xca, 0xf,
    0xfe, 0x2c, 0x1e, 0x43, 0xf6, 0x1f, 0xfc, 0x78,
    0x3e, 0x43, 0xc8, 0x7f, 0xf1, 0xd0, 0xf2, 0x1f,
    0xfd, 0x4, 0x3b, 0xf, 0x21, 0xff, 0xd6, 0x43,
    0xff, 0xd8, 0x87, 0x68, 0x7f, 0xf7, 0x60, 0xff,
    0xe3, 0xa1, 0xe4, 0x3e, 0x43, 0xff, 0x8f, 0x7,
    0x20, 0x83, 0xd8, 0x7f, 0xf1, 0x70, 0xf6, 0x4,
    0x3e, 0xc3, 0xff, 0x87, 0x87, 0xc8, 0x50, 0x7d,
    0xc1, 0xff, 0x58, 0x7d, 0x86, 0x60, 0xf9, 0xfa,
    0xbd, 0xe4, 0x3e, 0x83, 0xcc, 0x1f, 0xe5, 0xf0,
    0x7f, 0x48, 0x7c, 0xe1, 0xff, 0xca, 0x74, 0x3f,
    0xdc, 0x1f, 0xfc, 0x7a, 0x7, 0xff, 0x5, 0xe4,
    0x3f, 0xf8, 0x2f, 0x90, 0xff, 0xe2, 0x37, 0xd5,
    0xf7, 0xd0, 0x7f, 0x80,

    /* U+0039 "9" */
    0xf, 0xfe, 0x3, 0x7f, 0xa4, 0x3f, 0xf9, 0x4f,
    0xa4, 0x3c, 0xdc, 0x87, 0xff, 0x15, 0xe0, 0xff,
    0xe0, 0xb4, 0xf, 0xfe, 0x1d, 0x3, 0xff, 0x8a,
    0xe8, 0x7f, 0xf0, 0x24, 0x3f, 0xf9, 0x12, 0x1f,
    0xe9, 0xf, 0xcd, 0x64, 0x3f, 0x48, 0x7e, 0x50,
    0x7d, 0x72, 0xeb, 0x83, 0xe8, 0x3f, 0x41, 0xe7,
    0x43, 0xf3, 0xa1, 0xec, 0x3d, 0x7, 0x98, 0x3f,
    0xf8, 0x12, 0x1e, 0x43, 0x90, 0xf4, 0x1f, 0xfc,
    0x28, 0x3d, 0x6, 0x43, 0xd8, 0x7f, 0xf1, 0x30,
    0xf2, 0x16, 0x1f, 0xfc, 0xc4, 0x3b, 0x9, 0xe,
    0x83, 0xff, 0x8d, 0x7, 0x21, 0xfc, 0x87, 0xff,
    0x35, 0xf, 0xfe, 0x82, 0x1d, 0x88, 0x7f, 0xf3,
    0xb0, 0xe4, 0x3f, 0xfa, 0x8, 0x7f, 0xff, 0xc3,
    0xff, 0xb0, 0xa0, 0xff, 0xe7, 0x21, 0xff, 0xc2,
    0x43, 0xff, 0x8f, 0x87, 0xff, 0xa, 0xf, 0xfe,
    0x3a, 0x1f, 0x90, 0xff, 0xe6, 0x41, 0xfd, 0x7,
    0xb0, 0xff, 0xe2, 0x48, 0x7f, 0x90, 0xf4, 0x1f,
    0xfc, 0x29, 0xf, 0xfa, 0xf, 0x30, 0x7f, 0xce,
    0x87, 0xff, 0x6, 0xf, 0x3c, 0x87, 0x37, 0x6,
    0xc3, 0xc8, 0x4a, 0xf, 0x9b, 0xfa, 0x43, 0xa0,
    0xff, 0xe0, 0x48, 0x7f, 0xf1, 0xe4, 0x3f, 0xf8,
    0x34, 0xf, 0xfe, 0x2e, 0x88, 0x7f, 0xf0, 0x5d,
    0xf, 0xfe, 0xd, 0x87, 0xf2, 0x1f, 0xd7, 0x28,
    0x39, 0xbc, 0x86, 0xc3, 0xff, 0x8a, 0xd3, 0xfa,
    0x43, 0xe4, 0x3b, 0xf, 0xfe, 0xb2, 0x1f, 0xff,
    0x24, 0x39, 0xf, 0xfe, 0x84, 0x1d, 0x87, 0xff,
    0x59, 0xf, 0xfe, 0x7c, 0x1c, 0x87, 0xff, 0x3d,
    0x41, 0xd0, 0x7f, 0xf3, 0xe0, 0xe4, 0x3f, 0xf9,
    0xf0, 0x7a, 0xf, 0xfe, 0x74, 0x87, 0x21, 0xff,
    0xce, 0xd0, 0xf4, 0x1f, 0xfc, 0xcb, 0xf, 0xb0,
    0xff, 0x28, 0x3f, 0xcd, 0xa1, 0xf4, 0x1f, 0xf7,
    0x7d, 0x5b, 0xe9, 0xf, 0xda, 0x1f, 0xfc, 0x45,
    0xc1, 0xff, 0xc0, 0xc3, 0xff, 0xa9, 0x61, 0xff,
    0xd3, 0xb4, 0x3f, 0xfa, 0x2d, 0xa1, 0xff, 0xc5,
    0xbd, 0x5f, 0xbe, 0x90, 0xff, 0xe1, 0x80,

    /* U+0041 "A" */
    0xf, 0xfe, 0x47, 0xf8, 0x3f, 0xfb, 0x68, 0x7a,
    0xf, 0xfe, 0xd4, 0x1e, 0x43, 0xff, 0xb2, 0x87,
    0xe4, 0x3f, 0xfb, 0x18, 0x7e, 0xc3, 0xff, 0xb0,
    0x87, 0xe4, 0x3f, 0xfa, 0xe8, 0x7f, 0x90, 0xff,
    0xeb, 0x41, 0x90, 0xe8, 0x3f, 0xfa, 0xa8, 0x77,
    0x7, 0x21, 0xff, 0xd4, 0xc3, 0x94, 0x1d, 0x87,
    0xff, 0x51, 0xf, 0xfe, 0x2, 0x1f, 0xfd, 0x34,
    0x3a, 0x2, 0x1c, 0x87, 0xff, 0x4a, 0xe, 0x41,
    0x7, 0x41, 0xff, 0xff, 0x83, 0xa0, 0xc8, 0x74,
    0x1f, 0xfd, 0x4, 0x39, 0xd, 0x7, 0x21, 0xff,
    0xcf, 0x43, 0x90, 0xf2, 0x1c, 0x87, 0xff, 0x3a,
    0xe, 0xc3, 0xd8, 0x74, 0x1f, 0xfd, 0x44, 0x3c,
    0x87, 0xff, 0x4e, 0xe, 0x43, 0xf2, 0x1d, 0x7,
    0xff, 0x31, 0xe, 0x83, 0xf4, 0x1c, 0x87, 0xff,
    0x2d, 0xf, 0xfe, 0x52, 0x1f, 0xfc, 0xa8, 0x3a,
    0xf, 0xf4, 0x1d, 0x7, 0xff, 0x41, 0xf, 0xf2,
    0x1f, 0xfc, 0xf8, 0x39, 0xf, 0xfe, 0x2, 0x1d,
    0x7, 0xff, 0x21, 0xe, 0xc3, 0xff, 0x81, 0x87,
    0x21, 0xff, 0xc7, 0x43, 0xc8, 0x7f, 0xf0, 0x10,
    0xf2, 0x1f, 0xfc, 0x6c, 0x39, 0xf, 0xfe, 0x12,
    0x1d, 0x87, 0xff, 0x19, 0xe, 0x83, 0xff, 0x85,
    0x7, 0x21, 0xff, 0xc5, 0x83, 0xd5, 0xff, 0xc4,
    0xf, 0x21, 0xff, 0xc4, 0x43, 0xcb, 0xff, 0xc4,
    0xf, 0x41, 0xff, 0xc3, 0x43, 0xff, 0xa4, 0x87,
    0xff, 0xb, 0xf, 0xfe, 0x96, 0x1f, 0xfc, 0x24,
    0x3f, 0xfa, 0x48, 0x7f, 0xf0, 0x60, 0xff, 0xea,
    0x21, 0xff, 0xc0, 0x43, 0xaf, 0xff, 0xe4, 0x7,
    0xa0, 0xff, 0x90, 0xf2, 0x1f, 0xfc, 0x88, 0x3f,
    0xf8, 0xb8, 0x72, 0x1f, 0xfc, 0x94, 0x3d, 0x7,
    0xf9, 0xe, 0xc3, 0xff, 0x94, 0x87, 0x21, 0xfc,
    0x87, 0x90, 0xff, 0xe5, 0x41, 0xe4, 0x3f, 0x41,
    0xc8, 0x7f, 0xf4, 0xa0, 0xf9, 0xf, 0x41, 0xff,
    0xcc, 0x83, 0xff, 0x83, 0x87, 0xff, 0x4d, 0xf,
    0x41, 0xe4, 0x3a, 0xf, 0xfe, 0x72, 0x1c, 0x87,
    0x21, 0xe4, 0x3f, 0xf9, 0xd8, 0x79, 0xd, 0x7,
    0x21, 0xff, 0xcf, 0x43, 0xd0, 0x7f, 0xb0, 0xff,
    0xe8, 0x21, 0xfd, 0x7, 0x90, 0xff, 0xe8, 0x41,
    0xe8, 0x8, 0x72, 0x1f, 0xfd, 0x24, 0x39, 0x10,
    0xf4, 0x1f, 0xfd, 0x2c, 0x3c, 0xc1, 0xc8, 0x7f,
    0xf4, 0xd0, 0xf6,

    /* U+0043 "C" */
    0xf, 0xfe, 0x32, 0xaf, 0xfd, 0x45, 0x7, 0xff,
    0x29, 0xf5, 0x10, 0xfc, 0xaa, 0x79, 0xf, 0xfe,
    0x2d, 0xc1, 0xff, 0xc7, 0xb9, 0xf, 0xfe, 0x5,
    0xa1, 0xff, 0xcb, 0x60, 0xff, 0xb4, 0x3f, 0xf9,
    0xc8, 0x7f, 0x38, 0x7f, 0xf0, 0x57, 0x7, 0xfd,
    0x7, 0xe6, 0xf, 0xe6, 0xfa, 0xb7, 0xd2, 0x1c,
    0x87, 0xe6, 0xf, 0xcf, 0x21, 0xfe, 0x6f, 0x20,
    0x83, 0xf4, 0x1f, 0xb8, 0x3f, 0xf8, 0xb7, 0x7,
    0xec, 0x3e, 0x70, 0xff, 0xe4, 0xa1, 0xf4, 0x1f,
    0x30, 0x7f, 0xf4, 0x90, 0xf3, 0x7, 0xff, 0x4a,
    0xf, 0xa0, 0xff, 0xe9, 0xa1, 0xe8, 0x3f, 0xfa,
    0x70, 0x79, 0x41, 0xff, 0xd3, 0x43, 0xd8, 0x7f,
    0xf4, 0xd0, 0xf9, 0xf, 0xfe, 0x9e, 0x1e, 0x83,
    0xff, 0xa8, 0x87, 0x90, 0xff, 0xff, 0x84, 0x87,
    0xff, 0x51, 0xf, 0xff, 0x16, 0x1f, 0xff, 0xcc,
    0x3f, 0xff, 0xe1, 0xff, 0x21, 0xff, 0xdb, 0x43,
    0xff, 0xf9, 0x87, 0xff, 0xfc, 0x3f, 0xec, 0x3f,
    0xfa, 0x88, 0x79, 0xf, 0xff, 0xf8, 0x72, 0x1f,
    0xfd, 0x44, 0x3d, 0x87, 0xff, 0x53, 0xf, 0x21,
    0xff, 0xd4, 0x43, 0xe4, 0x3f, 0xfa, 0x88, 0x7a,
    0xf, 0xfe, 0xa4, 0x1f, 0x21, 0xff, 0xdb, 0x83,
    0xff, 0xa9, 0x7, 0xd8, 0x7f, 0xf4, 0xd4, 0x1f,
    0x41, 0xff, 0xd3, 0x83, 0xe7, 0xf, 0xfe, 0x9c,
    0x1f, 0xb4, 0x3f, 0xfa, 0x2a, 0xf, 0xd6, 0x87,
    0xff, 0x11, 0xb4, 0x3f, 0x48, 0x7f, 0x5e, 0x94,
    0x19, 0x6b, 0xe9, 0xf, 0xfa, 0x43, 0xfe, 0x69,
    0xfa, 0xa4, 0x3f, 0xf8, 0xb4, 0xf, 0xfe, 0xdb,
    0xa1, 0xff, 0xdb, 0xb4, 0x3f, 0xf9, 0x4a, 0xf,
    0xfe, 0x1d, 0xc8, 0x7f, 0xf0, 0xd5, 0x70, 0x7f,
    0xf1, 0x9b, 0xea, 0xfe, 0xfa, 0x88, 0x70,

    /* U+004E "N" */
    0x3f, 0xf0, 0x7f, 0xf3, 0x9f, 0xe8, 0x3f, 0x90,
    0xff, 0xee, 0xc1, 0xff, 0xde, 0x83, 0xff, 0xba,
    0xa0, 0xff, 0xee, 0xc1, 0xff, 0xde, 0x83, 0xff,
    0xba, 0xa0, 0xff, 0xee, 0xc1, 0xff, 0xd6, 0x83,
    0xe8, 0x3f, 0xfa, 0xd8, 0x79, 0x41, 0xff, 0xd4,
    0xc8, 0x3d, 0x7, 0xff, 0x59, 0xf, 0xa0, 0xff,
    0xeb, 0x61, 0xe4, 0x3f, 0xfa, 0xe8, 0x7b, 0xf,
    0xfe, 0x92, 0x14, 0x1f, 0x41, 0xff, 0xd6, 0xc3,
    0xc8, 0x7f, 0xf5, 0xd0, 0xf6, 0x1f, 0xfd, 0x68,
    0x3e, 0x43, 0xff, 0xad, 0x7, 0xa0, 0xff, 0xeb,
    0x28, 0x3d, 0x87, 0xff, 0x5a, 0xf, 0x90, 0xff,
    0xeb, 0x41, 0xe8, 0x3f, 0xfa, 0xca, 0xf, 0x41,
    0xff, 0xd6, 0x83, 0xca, 0xf, 0xfe, 0xb4, 0x1e,
    0x83, 0xff, 0xac, 0xa0, 0xf4, 0x1f, 0xfd, 0x68,
    0x3c, 0xa0, 0xff, 0xeb, 0x41, 0xe8, 0x3f, 0xfa,
    0xc8, 0x7d, 0x7, 0xff, 0x5b, 0xf, 0x28, 0x3f,
    0xfa, 0xd0, 0x7a, 0xf, 0xfe, 0xb2, 0x1f, 0x41,
    0xc8, 0x7f, 0xf4, 0x30, 0xf2, 0x1f, 0xfd, 0x74,
    0x3d, 0x87, 0xff, 0x5a, 0xf, 0xa0, 0xff, 0xeb,
    0x61, 0xe4, 0x3f, 0xfa, 0xe8, 0x7b, 0xf, 0xfe,
    0xb4, 0x1f, 0x21, 0xff, 0xd6, 0x83, 0xd0, 0x7f,
    0xf5, 0x94, 0x1e, 0xc3, 0xff, 0xad, 0x7, 0xc8,
    0x7f, 0xf5, 0xa0, 0xf4, 0x1f, 0xfd, 0x65, 0x7,
    0xff, 0x76, 0xf, 0xfe, 0xf4, 0x1f, 0xfd, 0xd5,
    0x7, 0xff, 0x76, 0xf, 0xfe, 0xf4, 0x1f, 0xfd,
    0xd4, 0x3f, 0xfb, 0xd8, 0x7e,

    /* U+0061 "a" */
    0xf, 0xfe, 0x12, 0xfc, 0x1f, 0xfc, 0x9a, 0x7a,
    0xbe, 0xf9, 0xf, 0xfe, 0x15, 0xe5, 0x7, 0xff,
    0x2, 0xe0, 0xff, 0x5a, 0x1f, 0xfc, 0x67, 0xf,
    0xe4, 0x3f, 0xf9, 0x58, 0x7e, 0x43, 0xf9, 0x78,
    0x3f, 0xa0, 0xfb, 0xe, 0xbe, 0xae, 0xe0, 0xf9,
    0xf, 0x90, 0x5e, 0x43, 0xf9, 0xd0, 0xf4, 0x1f,
    0x79, 0xf, 0xfe, 0x14, 0x1e, 0x43, 0xff, 0x9b,
    0x7, 0xff, 0x4d, 0xf, 0x21, 0xff, 0xed, 0x43,
    0xb0, 0xff, 0xff, 0x87, 0xff, 0x51, 0xa7, 0xff,
    0xc8, 0x7f, 0xf0, 0xaf, 0x4a, 0xf, 0xfe, 0x5b,
    0xe4, 0x3f, 0xf9, 0xf4, 0xf, 0xfe, 0x8c, 0x87,
    0xf2, 0xab, 0xf8, 0x3f, 0xa4, 0x3e, 0xbd, 0x45,
    0xff, 0x7, 0xca, 0xf, 0x3a, 0x1f, 0xfc, 0x98,
    0x3d, 0x40, 0xff, 0xe9, 0x21, 0xff, 0xc4, 0x43,
    0xc8, 0x7a, 0xf, 0xfe, 0x66, 0x1e, 0x43, 0xff,
    0xc8, 0x87, 0xff, 0x4f, 0xf, 0xfe, 0x9a, 0x1f,
    0x61, 0xff, 0xca, 0x83, 0xff, 0x87, 0x7, 0xff,
    0xa, 0x43, 0xf2, 0x1e, 0x50, 0x7f, 0xf0, 0x34,
    0x3f, 0xc8, 0x7a, 0x81, 0xf9, 0xb0, 0xc8, 0x7d,
    0x7, 0xcf, 0xab, 0x7a, 0x43, 0x50, 0x3f, 0x41,
    0xfc, 0xb8, 0x3e, 0x90, 0xfe, 0x60, 0xff, 0xe3,
    0x48, 0x10, 0xfc, 0xe1, 0xff, 0xc4, 0xd0, 0xb0,
    0xff, 0x72, 0x1f, 0xe6, 0xc3, 0x90, 0xff, 0x9b,
    0xd5, 0xef, 0x48, 0x7d, 0xfa,

    /* U+0063 "c" */
    0xf, 0xfe, 0x22, 0xf8, 0x3f, 0xf9, 0x17, 0xd5,
    0xef, 0xa4, 0x3f, 0xf8, 0xf, 0x90, 0xff, 0xe0,
    0x37, 0x7, 0xf5, 0x3, 0xff, 0x8c, 0x87, 0xed,
    0xf, 0xfe, 0x3c, 0x1e, 0x70, 0xff, 0xe4, 0xa1,
    0xe8, 0x3f, 0x37, 0xfa, 0x42, 0x43, 0xd8, 0x7c,
    0xf2, 0x1e, 0x6f, 0x58, 0x72, 0x1f, 0x50, 0x3f,
    0xf8, 0x2a, 0xe, 0x83, 0xd2, 0x1f, 0xfc, 0x84,
    0x3e, 0x43, 0xff, 0x93, 0x7, 0xb0, 0xff, 0xf3,
    0xa1, 0xe8, 0x3f, 0xf9, 0x58, 0x79, 0xf, 0xff,
    0x42, 0x1f, 0xfd, 0x74, 0x3f, 0xff, 0xe1, 0xff,
    0xff, 0xf, 0xff, 0x4a, 0x1c, 0x87, 0xff, 0xa7,
    0xf, 0x21, 0xff, 0xca, 0x43, 0xd8, 0x7f, 0xf4,
    0x50, 0xff, 0xe5, 0xa1, 0xe8, 0x3f, 0xf9, 0x50,
    0x79, 0x41, 0xff, 0xca, 0x43, 0xd2, 0x1f, 0xfc,
    0x98, 0x3e, 0xa0, 0x7f, 0xf0, 0x5a, 0x7, 0x41,
    0xf3, 0xc8, 0x79, 0x57, 0x21, 0xe6, 0xf, 0xcd,
    0xfe, 0xa2, 0x1f, 0xe6, 0xf, 0xfe, 0x8b, 0x87,
    0xff, 0x4b, 0x83, 0xff, 0x8d, 0x87, 0xf9, 0xe4,
    0x3f, 0xf8, 0xd, 0xa1, 0xff, 0xc0, 0x6f, 0x57,
    0xdf, 0x48, 0x40,

    /* U+006E "n" */
    0xf, 0xfe, 0x22, 0xf8, 0x3f, 0xef, 0xe4, 0x3c,
    0xde, 0xaf, 0x7a, 0x43, 0xff, 0x8a, 0xf2, 0x1f,
    0xe6, 0xd0, 0xff, 0x61, 0x50, 0x3f, 0xf8, 0x94,
    0xf, 0xe4, 0x1a, 0x1f, 0xfc, 0x66, 0xf, 0xf6,
    0x1f, 0xfc, 0x95, 0x7, 0xec, 0x39, 0xbf, 0xe8,
    0x3f, 0x41, 0xff, 0xc0, 0x79, 0xf, 0x9e, 0xf,
    0x90, 0xff, 0x30, 0x7f, 0xf0, 0x18, 0x3d, 0x7,
    0xfa, 0xf, 0xfe, 0x12, 0x1f, 0xfc, 0x4c, 0x3f,
    0xf8, 0x90, 0x79, 0xf, 0xfe, 0x6a, 0x1f, 0xfc,
    0x28, 0x3f, 0xf9, 0x98, 0x7c, 0x87, 0xff, 0x19,
    0xf, 0xff, 0xa, 0x1f, 0xff, 0xf0, 0xff, 0xe5,
    0xe1, 0xff, 0xff, 0xf, 0xff, 0xf8, 0x7f, 0xff,
    0xc3, 0xff, 0xfe, 0x1f, 0xff, 0xf0, 0xff, 0xff,
    0x87, 0xff, 0xfc, 0x3f, 0xff, 0xe1, 0xff, 0xff,
    0xf, 0xf8,

    /* U+00B0 "°" */
    0xf, 0xcd, 0xfd, 0x21, 0xff, 0xc1, 0xb9, 0xe,
    0x6d, 0xf, 0xe7, 0x43, 0xfe, 0xb0, 0xf9, 0x83,
    0xff, 0x87, 0x87, 0xa0, 0xe6, 0xfa, 0x43, 0xb0,
    0xd0, 0x77, 0x21, 0x36, 0x1c, 0x84, 0x86, 0xc3,
    0xfb, 0xd, 0x2, 0xd, 0x7, 0xfc, 0x86, 0x44,
    0x32, 0x1f, 0xf4, 0x1b, 0xf, 0xfe, 0x8a, 0x1f,
    0xfc, 0x54, 0x3f, 0xfa, 0x28, 0x7f, 0xf1, 0x50,
    0xff, 0xe6, 0xa1, 0x90, 0xff, 0xa0, 0xd9, 0x6,
    0x83, 0xfe, 0x43, 0x20, 0x43, 0x61, 0xfd, 0x86,
    0x82, 0x83, 0xb9, 0x42, 0xac, 0x39, 0xd, 0x7,
    0x34, 0xe8, 0x87, 0x61, 0xcc, 0x1f, 0xfc, 0x3c,
    0x3e, 0x74, 0x3f, 0xe7, 0xf, 0xf5, 0xc8, 0x73,
    0x70, 0x70
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 371, .box_w = 19, .box_h = 6, .ofs_x = 2, .ofs_y = 16},
    {.bitmap_index = 9, .adv_w = 309, .box_w = 10, .box_h = 11, .ofs_x = 5, .ofs_y = -1},
    {.bitmap_index = 32, .adv_w = 659, .box_w = 35, .box_h = 53, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 283, .adv_w = 659, .box_w = 20, .box_h = 51, .ofs_x = 6, .ofs_y = 0},
    {.bitmap_index = 367, .adv_w = 659, .box_w = 35, .box_h = 52, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 592, .adv_w = 659, .box_w = 35, .box_h = 53, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 836, .adv_w = 659, .box_w = 39, .box_h = 52, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1021, .adv_w = 659, .box_w = 34, .box_h = 52, .ofs_x = 4, .ofs_y = -1},
    {.bitmap_index = 1204, .adv_w = 659, .box_w = 35, .box_h = 53, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 1489, .adv_w = 659, .box_w = 35, .box_h = 51, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 1690, .adv_w = 659, .box_w = 35, .box_h = 53, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 2006, .adv_w = 659, .box_w = 35, .box_h = 53, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 2285, .adv_w = 736, .box_w = 46, .box_h = 51, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2600, .adv_w = 728, .box_w = 40, .box_h = 53, .ofs_x = 4, .ofs_y = -1},
    {.bitmap_index = 2839, .adv_w = 876, .box_w = 42, .box_h = 51, .ofs_x = 6, .ofs_y = 0},
    {.bitmap_index = 3044, .adv_w = 646, .box_w = 32, .box_h = 40, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 3233, .adv_w = 553, .box_w = 30, .box_h = 40, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 3388, .adv_w = 712, .box_w = 33, .box_h = 39, .ofs_x = 6, .ofs_y = 0},
    {.bitmap_index = 3502, .adv_w = 493, .box_w = 24, .box_h = 22, .ofs_x = 3, .ofs_y = 30}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x1, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8,
    0x9, 0xa, 0xb, 0xc, 0x14, 0x16, 0x21, 0x34,
    0x36, 0x41, 0x83
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 45, .range_length = 132, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 19, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    2, 14,
    13, 14,
    14, 14
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    -58, -23, -23
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 3,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR >= 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_pairs,
    .kern_scale = 16,
    .cmap_num = 1,
    .bpp = 2,
    .kern_classes = 0,
    .bitmap_format = 1,
#if LVGL_VERSION_MAJOR >= 8
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t Noto72compressed = {
#else
lv_font_t Noto72compressed = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 53,          /*The maximum line height required by the font*/
    .base_line = 1,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -7,
    .underline_thickness = 4,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
    .fallback = NULL,
    .user_data = NULL
};



#endif /*#if NOTO72COMPRESSED*/

