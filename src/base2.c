/*
 * Copyright 2020-2021 @bynect
 *
 * This is free and open source software.
 * You can use/modify/redistribute it under the terms of the MIT license.
 * See docs/LICENSE for for more details.
 */


#include <basex/base2.h>


char *
base2_encode(const unsigned char *src, int len, int pad)
{
    char *out, *ptr;
    unsigned int size;
    int i, j;

    if (src == NULL)
        return NULL;

    size = len * 8;
    out = malloc((size + 1) * sizeof(char));
    ptr = out;

    for (i = 0; i < len; ++i) {
        const char c = *src++;

        for(j = 7; j >= 0; --j){
            *ptr++ = (c & (1 << j)) ? '1' : '0';
        }
    }

    *ptr = 0;
    return out;
}


unsigned char *
base2_decode(const char *src, int len)
{
    unsigned char *out, *ptr;
    unsigned int size;
    int i, j;

    if (src == NULL)
        return NULL;

    size = len /= 8;
    out = malloc((size + 1) * sizeof(unsigned char));
    ptr = out;

    for (i = 0; i < len; ++i) {
        unsigned char c = 0;

        for(j = 0; j < 8; ++j) {
            c <<= 1;
            c += *(src + j) - '0';

        }

        *ptr++ = c;
        src += 8;
    }

    *ptr = 0;
    return out;
}
