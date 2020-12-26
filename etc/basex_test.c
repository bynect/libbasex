/*
 * Copyright 2020 @bynect
 *
 * This is free and open source software.
 * You can use/modify/redistribute it under the terms of the MIT license.
 * See docs/LICENSE for for more details.
 */


#include <basex.h>
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


#define basex_test(x)                                                   \
    char *enc0_ ## x;                                                   \
    char *enc1_ ## x;                                                   \
    char *enc2_ ## x;                                                   \
    char *enc3_ ## x;                                                   \
    char *enc4_ ## x;                                                   \
    char *enc5_ ## x;                                                   \
    char *enc6_ ## x;                                                   \
                                                                        \
    unsigned char *dec0_ ## x;                                          \
    unsigned char *dec1_ ## x;                                          \
    unsigned char *dec2_ ## x;                                          \
    unsigned char *dec3_ ## x;                                          \
    unsigned char *dec4_ ## x;                                          \
    unsigned char *dec5_ ## x;                                          \
    unsigned char *dec6_ ## x;                                          \
                                                                        \
    enc0_ ## x = base ## x ## _encode(src0, strlen(src0), 1);           \
    enc1_ ## x = base ## x ## _encode(src1, strlen(src1), 1);           \
    enc2_ ## x = base ## x ## _encode(src2, strlen(src2), 1);           \
    enc3_ ## x = base ## x ## _encode(src3, strlen(src3), 1);           \
    enc4_ ## x = base ## x ## _encode(src4, strlen(src4), 1);           \
    enc5_ ## x = base ## x ## _encode(src5, strlen(src5), 1);           \
    enc6_ ## x = base ## x ## _encode(src6, strlen(src6), 1);           \
                                                                        \
    dec0_ ## x = base ## x ## _decode(enc0_ ## x, strlen(enc0_ ## x));  \
    dec1_ ## x = base ## x ## _decode(enc1_ ## x, strlen(enc1_ ## x));  \
    dec2_ ## x = base ## x ## _decode(enc2_ ## x, strlen(enc2_ ## x));  \
    dec3_ ## x = base ## x ## _decode(enc3_ ## x, strlen(enc3_ ## x));  \
    dec4_ ## x = base ## x ## _decode(enc4_ ## x, strlen(enc4_ ## x));  \
    dec5_ ## x = base ## x ## _decode(enc5_ ## x, strlen(enc5_ ## x));  \
    dec6_ ## x = base ## x ## _decode(enc6_ ## x, strlen(enc6_ ## x));  \
                                                                        \
    assert(!strcmp(src0, dec0_ ## x));                                  \
    assert(!strcmp(src1, dec1_ ## x));                                  \
    assert(!strcmp(src2, dec2_ ## x));                                  \
    assert(!strcmp(src3, dec3_ ## x));                                  \
    assert(!strcmp(src4, dec4_ ## x));                                  \
    assert(!strcmp(src5, dec5_ ## x));                                  \
    assert(!strcmp(src6, dec6_ ## x));                                  \
                                                                        \
    free(enc0_ ## x);                                                   \
    free(enc1_ ## x);                                                   \
    free(enc2_ ## x);                                                   \
    free(enc3_ ## x);                                                   \
    free(enc4_ ## x);                                                   \
    free(enc5_ ## x);                                                   \
    free(enc6_ ## x);                                                   \
                                                                        \
    free(dec0_ ## x);                                                   \
    free(dec1_ ## x);                                                   \
    free(dec2_ ## x);                                                   \
    free(dec3_ ## x);                                                   \
    free(dec4_ ## x);                                                   \
    free(dec5_ ## x);                                                   \
    free(dec6_ ## x);


static void
base16_test(void)
{
    basex_test(16);
    printf("Base16 test passed.\n");
}


static void
base32_test(void)
{
    basex_test(32);
    printf("Base32 test passed.\n");
}


static void
base32hex_test(void)
{
    basex_test(32hex);
    printf("Base32hex test passed.\n");
}


static void
base64_test(void)
{
    basex_test(64);
    printf("Base64 test passed.\n");
}


static void
base64url_test(void)
{
    basex_test(64url);
    printf("Base64url test passed.\n");
}


int
main(int argc, char **argv)
{
    base16_test();

    base32_test();
    base32hex_test();

    base64_test();
    base64url_test();

    return 0;
}
