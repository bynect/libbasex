#ifndef _BASE32HEX_H
#define _BASE32HEX_H


#include <stddef.h>
#include <string.h>
#include <malloc.h>


char *base32hex_encode(const unsigned char *src, int len, int pad);


unsigned char *base32hex_decode(const unsigned char *src, int len);


#endif /*_BASE32HEX_H*/
