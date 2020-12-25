/*
 * Copyright 2020 @bynect
 *
 * This program is free and open source software.
 * You can use/modify/redistribute it under the terms of the MIT license.
 * See etc/LICENSE for for more details.
 */


#include <basex/base58.h>


char *
base58_encode(const unsigned char *src, int len)
{
    const char encoding_table[58] = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";

    char *out, *ptr;
    unsigned char *buff;
    unsigned int zero, size, high;
    int i, j, carry;

    if (src == NULL)
        return NULL;

    zero = 0;
    size = (len - zero) * 138 / 100;
    buff = calloc(size + 1, sizeof(unsigned char));

    while (zero < len && *(src + zero) == 0) {
        ++zero;
    }

    for (i = zero, high = size; i < len; ++i, high = j) {
        for (carry = *(src + i), j = size; (j > high) || carry; --j) {
            carry += 256 * buff[j];
            *(buff + j) = carry % 58;
            carry /= 58;

            if (!j) break;
        }
    }

    for (j = 0; j < (size + 1) && !buff[j]; ++j);
        
    out = calloc(zero + size - j + 1, sizeof(char));
    ptr = out;

    if (zero) {
        memset(out, '1', zero);
    }

    ptr += zero;
    for (; j < size + 1; ++j) {
        *ptr++ = encoding_table[buff[j]];
    }

    free(buff);
    return out;
}


unsigned char *
base58_decode(const unsigned char *src, int len)
{
    const char decoding_table[256] = {
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, -1, -1, -1, -1, -1, -1,
        -1, 9, 10, 11, 12, 13, 14, 15, 16, -1, 17, 18, 19, 20, 21, -1,
        22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, -1, -1, -1, -1, -1,
        -1, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, -1, 44, 45, 46,
        47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    };

    if (src == NULL)
        return NULL;


    /*TODO*/
    return NULL;
}
