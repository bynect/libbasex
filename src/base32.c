/*
 * Copyright 2020 @bynect
 *
 * This is free and open source software.
 * You can use/modify/redistribute it under the terms of the MIT license.
 * See docs/LICENSE for for more details.
 */


#include <basex/base32.h>


char *
base32_encode(const unsigned char *src, int len, int pad)
{
    const char encoding_table[32] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";

    char *out, *ptr;
    unsigned int bits, buff;
    int rem, i;

    if (src == NULL)
        return NULL;

    out = malloc((((len * 8 + 4) / 5) + 7) * sizeof(char));
    ptr = out;

    bits = 0;
    buff = 0;

    for (i = 0; i < len; ++i) {
        buff <<= 8;
        buff += (unsigned int)(*src++);
        bits += 8;
        while (bits >= 5) {
            *ptr++ = encoding_table[(buff >> (bits - 5)) & 0x3f];
            buff &= ~(0x1f << (bits - 5));
            bits -= 5;
        }
    }

    rem = len % 5;

    if (rem == 1) {
        buff <<= 2;
        *ptr++ = encoding_table[buff & 0x1f];
        if (pad) {
            sprintf(ptr, "%s", "======");
            ptr += 6;
        }

    } else if (rem == 2) {
        buff <<= 4;
        *ptr++ = encoding_table[buff & 0x1f];
        if (pad) {
            sprintf(ptr, "%s", "====");
            ptr += 4;
        }

    } else if (rem == 3) {
        buff <<= 1;
        *ptr++ = encoding_table[buff & 0x1f];
        if (pad) {
            sprintf(ptr, "%s", "===");
            ptr += 3;
        }

    } else if (rem == 4) {
        buff <<= 3;
        *ptr++ = encoding_table[buff & 0x1f];
        if (pad)
            *ptr++ = '=';
    }

    *ptr = 0;
    return out;
}


unsigned char *
base32_decode(const unsigned char *src, int len)
{
    const char decoding_table[256] = {
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, 26, 27, 28, 29, 30, 31, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
        15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -1, -1, -1, -1, -1,
        -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
        15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -1, -1, -1, -1, -1,
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
    unsigned int bits, buff;
    int i;

    if (src == NULL)
        return NULL;

    out = malloc(((len / 1.6) + 1) * sizeof(unsigned char));
    ptr = out;

    bits = 0;
    buff = 0;
    for (i = 0; i < len; ++i) {
        const unsigned char c = *src++;
        const int group = decoding_table[c];

        if (c == -1)
            return NULL;

        buff <<= 5;
        bits += 5;

        if (group != -1)
            buff += group;

        if (bits >= 8) {
            if (c != '=')
                *ptr++ = (char)(buff >> (bits - 8));

            buff &= ~(0xff << (bits - 8));
            bits -= 8;
        }
    }

    *ptr = 0;
    return out;
}
