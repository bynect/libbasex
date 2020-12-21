#ifndef _BASE64_H
#define _BASE64_H


#include <stdint.h>
#include <stddef.h>
#include <string.h>


char *base64_encode(const unsigned char *src, int len, int pad);


unsigned char *base64_decode(const unsigned char *src, int len);


#endif /*_BASE64_H*/
