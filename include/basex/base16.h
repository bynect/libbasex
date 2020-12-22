#ifndef _BASE16_H
#define _BASE16_H


#include <stdint.h>
#include <stddef.h>
#include <string.h>


char *base16_encode(const unsigned char *src, int len, int pad);


unsigned char *base16_decode(const unsigned char *src, int len);


#endif /*_BASE16_H*/
