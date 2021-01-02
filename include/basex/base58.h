/*
 * Copyright 2020-2021 @bynect
 *
 * This is free and open source software.
 * You can use/modify/redistribute it under the terms of the MIT license.
 * See docs/LICENSE for for more details.
 */


#ifndef _BASE58_H
#define _BASE58_H


#include <stddef.h>
#include <string.h>
#include <malloc.h>


char *base58_encode(const unsigned char *src, int len, int pad);


unsigned char *base58_decode(const char *src, int len);


#endif /*_BASE58_H*/
