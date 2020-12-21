#include <basex/base32.h>
#include <basex/base64.h>
#include <stdio.h>
#include <malloc.h>
#include <assert.h>


static char *src0 = "";
static char *src1 = "f";
static char *src2 = "fo";
static char *src3 = "foo";
static char *src4 = "foob";
static char *src5 = "fooba";
static char *src6 = "foobar";


#define basex_test(encode, decode)                          \
    char *enc0;                                             \
    char *enc1;                                             \
    char *enc2;                                             \
    char *enc3;                                             \
    char *enc4;                                             \
    char *enc5;                                             \
    char *enc6;                                             \
                                                            \
    unsigned char *dec0;                                    \
    unsigned char *dec1;                                    \
    unsigned char *dec2;                                    \
    unsigned char *dec3;                                    \
    unsigned char *dec4;                                    \
    unsigned char *dec5;                                    \
    unsigned char *dec6;                                    \
                                                            \
    enc0 = encode(src0, strlen(src0), 1);                   \
    enc1 = encode(src1, strlen(src1), 1);                   \
    enc2 = encode(src2, strlen(src2), 1);                   \
    enc3 = encode(src3, strlen(src3), 1);                   \
    enc4 = encode(src4, strlen(src4), 1);                   \
    enc5 = encode(src5, strlen(src5), 1);                   \
    enc6 = encode(src6, strlen(src6), 1);                   \
                                                            \
    dec0 = decode(enc0, strlen(enc0));                      \
    dec1 = decode(enc1, strlen(enc1));                      \
    dec2 = decode(enc2, strlen(enc2));                      \
    dec3 = decode(enc3, strlen(enc3));                      \
    dec4 = decode(enc4, strlen(enc4));                      \
    dec5 = decode(enc5, strlen(enc5));                      \
    dec6 = decode(enc6, strlen(enc6));                      \
                                                            \
    assert(!strcmp(src0, dec0));                            \
    assert(!strcmp(src1, dec1));                            \
    assert(!strcmp(src2, dec2));                            \
    assert(!strcmp(src3, dec3));                            \
    assert(!strcmp(src4, dec4));                            \
    assert(!strcmp(src5, dec5));                            \
    assert(!strcmp(src6, dec6));                            \
                                                            \
    free(enc0);                                             \
    free(enc1);                                             \
    free(enc2);                                             \
    free(enc3);                                             \
    free(enc4);                                             \
    free(enc5);                                             \
    free(enc6);                                             \
                                                            \
    free(dec0);                                             \
    free(dec1);                                             \
    free(dec2);                                             \
    free(dec3);                                             \
    free(dec4);                                             \
    free(dec5);                                             \
    free(dec6);


static void
base32_test(void)
{
    basex_test(base32_encode, base32_decode);
    printf("Base32 test passed.\n");
}


static void
base64_test(void)
{
    basex_test(base64_encode, base64_decode);
    printf("Base64 test passed.\n");
}


int main(int argc, char **argv)
{
    base32_test();
    base64_test();

    printf("All test passed.\n");
}
