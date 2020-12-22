/*
 * Copyright 2020 @bynect
 *
 * This program is free and open source software.
 * You can use/modify/redistribute it under the terms of the MIT license.
 * See etc/LICENSE for for more details.
 */


#ifndef _BASE64URL_H
#define _BASE64URL_H


#include <stddef.h>
#include <string.h>
#include <malloc.h>


char *base64url_encode(const unsigned char *src, int len, int pad);


unsigned char *base64url_decode(const unsigned char *src, int len);


#endif /*_BASE64URL_H*/
