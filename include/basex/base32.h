#ifndef _BASE32_H
#define _BASE32_H


#include <stddef.h>
#include <string.h>
#include <malloc.h>


char *base32_encode(const unsigned char *src, int len, int pad);


unsigned char *base32_decode(const unsigned char *src, int len);


#endif /*_BASE32_H*/
