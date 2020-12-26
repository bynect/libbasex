/*
 * Copyright 2020 @bynect
 *
 * This is free and open source software.
 * You can use/modify/redistribute it under the terms of the MIT license.
 * See docs/LICENSE for for more details.
 */


#ifndef _BASE16_H
#define _BASE16_H


#include <stddef.h>
#include <string.h>
#include <malloc.h>


char *base16_encode(const unsigned char *src, int len, int pad);


unsigned char *base16_decode(const unsigned char *src, int len);


#endif /*_BASE16_H*/
