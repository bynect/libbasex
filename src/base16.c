/*
 * Copyright 2020 @bynect
 *
 * This is free and open source software.
 * You can use/modify/redistribute it under the terms of the MIT license.
 * See docs/LICENSE for for more details.
 */


#include <basex/base16.h>


char *
base16_encode(const unsigned char *src, int len, int pad)
{
    const char encoding_table[16] = "0123456789ABCDEF";

    char *out, *ptr;
    unsigned int size;
    int i;

    if (src == NULL)
        return NULL;

    size = len * 2;
    out = malloc((size + 1) * sizeof(char));
    ptr = out;

    for (i = 0; i < len; ++i) {
        const unsigned char c = *src++;
        *ptr++ = encoding_table[c >> 4];
        *ptr++ = encoding_table[c & 0x0f];
    }

    *ptr = 0;
    return out;
}


unsigned char *
base16_decode(const char *src, int len)
{
    const char decoding_table[256] = {
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -1, -1, -1, -1, -1, -1,
        -1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    };

    unsigned char *out, *ptr;
    unsigned int size;
    int i;

    if (src == NULL)
        return NULL;

    size = (len /= 2);
    out = malloc((size + 1) * sizeof(unsigned char));
    ptr = out;

    for (i = 0; i < len; ++i) {
        const unsigned char c1 = *src++, c2 = *src++;

        const unsigned char b1 = decoding_table[c1];
        const unsigned char b2 = decoding_table[c2];

        if (b1 == -1 || b2 == -1)
            return NULL;

        *ptr++ = (b1 << 4) | b2;
    }

    *ptr = 0;
    return out;
}
