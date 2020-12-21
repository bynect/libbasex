#include <basex/base32.h>
#include <malloc.h>


static const char encoding_table[32] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";


static const char decoding_table[256] = {
   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
   -1, -1, 26, 27, 28, 29, 30, 31, -1, -1, -1, -1, -1, -1, -1, -1,
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
   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
};


char *
base32_encode(const unsigned char *src, int len, int pad)
{
    if (src == NULL || len == 0)
        return NULL;

    char *out = calloc((len + 7), sizeof(char));
    char *ptr = out;

    unsigned int bits = 0;
    unsigned int buff = 0;

    int i = 0;
    for (i = 0; i < len; ++i) {
        buff <<= 8;
        buff += (unsigned int)(*src++);
        bits += 8;
        while (bits >= 5) {
            sprintf(ptr++, "%c", encoding_table[(buff >> (bits - 5)) & 0x3f]);
            buff &= ~(0x1f << (bits - 5));
            bits -= 5;
        }
    }

    unsigned int rem = len % 5;

    if (rem == 1) {
        buff <<= 2;
        sprintf(ptr++, "%c", encoding_table[buff & 0x1f]);
        if (pad) {
            sprintf(ptr, "%s", "======");
            ptr += 6;
        }

    } else if (rem == 2) {
        buff <<= 4;
        sprintf(ptr++, "%c", encoding_table[buff & 0x1f]);
        if (pad) {
            sprintf(ptr, "%s", "====");
            ptr += 4;
        }

    } else if (rem == 3) {
        buff <<= 1;
        sprintf(ptr++, "%c", encoding_table[buff & 0x1f]);
        if (pad) {
            sprintf(ptr, "%s", "===");
            ptr += 3;
        }

    } else if (rem == 4) {
        buff <<= 3;
        sprintf(ptr++, "%c", encoding_table[buff & 0x1f]);
        if (pad)
            sprintf(ptr++, "%c", '=');
    }

    *ptr = 0;
    return out;
}


unsigned char *
base32_decode(const unsigned char *src, int len)
{
    if (src == NULL || len == 0)
        return NULL;

    char *out = calloc((len + 7), sizeof(char));
    char *ptr = out;

    unsigned int bits = 0;
    unsigned int buff = 0;

    int i = 0;
    for (i = 0; i < len; ++i) {
        const unsigned char c = *src++;
        const int group = decoding_table[c];

        buff <<= 5;
        bits += 5;
        if (group != -1) {
            printf("%d  ", group);
            buff += group;
        }

        if (bits >= 8) {
            if (c != '=')
                *ptr++ = (char)(buff >> (bits - 8));

            buff &= ~(0xff << (bits - 8));
            bits -= 8;
        }
    }

    return out;
}
