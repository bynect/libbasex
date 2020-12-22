#ifndef _BASE64URL_H
#define _BASE64URL_H


#include <stddef.h>
#include <string.h>
#include <malloc.h>


char *base64url_encode(const unsigned char *src, int len, int pad);


unsigned char *base64url_decode(const unsigned char *src, int len);


#endif /*_BASE64URL_H*/
