#include <basex/base32.h>
#include <malloc.h>


char *
base16_encode(const unsigned char *src, int len, int pad)
{
    const char encoding_table[16] = "0123456789ABCDEF";

    char *out, *ptr;
    int i;

    if (src == NULL)
        return NULL;

    out = calloc((len * 2) + 1, sizeof(char));
    ptr = out;

    for (i = 0; i < len; ++i) {
        const unsigned char c = *src++;
        *ptr++ = encoding_table[c >> 4];
        *ptr++ = encoding_table[c & 0x0F];
    }

    *ptr = 0;
    return out;
}


unsigned char *
base16_decode(const unsigned char *src, int len)
{
    const char decoding_table[256] = {
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -1, -1, -1, -1, -1, -1,
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
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    };

    unsigned char *out, *ptr;
    int i;

    if (src == NULL)
        return NULL;

    out = calloc((len / 2) + 1, sizeof(char));
    ptr = out;

    for (i = 0; i < len / 2; ++i) {
        const unsigned char b1 = decoding_table[*src++];
        const unsigned char b2 = decoding_table[*src++];
        *ptr++ = (b1 << 4) | b2;
    }

    *ptr = 0;
    return out;
}