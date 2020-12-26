#! /usr/bin/env bash
# Copyright 2020 @bynect
# This is free and open source software.
# You can use/modify/redistribute it under the terms of the MIT license.
# See docs/LICENSE for for more details.

set -e

srcdir=${srcdir:-"./src"}
libdir=${libdir:-"./lib"}
objdir=${objdir:-"$libdir/obj"}
incdir=${incdir:-"./include"}

static=${static:-"$libdir/libbasex.a"}
shared=${shared:-"$libdir/libbasex.so"}

cc=gcc
cflags="-ansi -Wall -I$incdir"

if test ! -d "$libdir"; then
    mkdir -p "$libdir"
fi

if test ! -d "$objdir"; then
    mkdir -p "$objdir"
fi

for srcfile in $srcdir/*.c; do
    $cc $cflags -c $srcfile -o "$objdir/$(basename $srcfile .c)_static.o"
    $cc $cflags -c $srcfile -fpic -o "$objdir/$(basename $srcfile .c)_dynamic.o"
done

#static library
ar rcs $static $objdir/*_static.o
echo "$static compiled."

#shared library
$cc $cflags -shared -o $shared $objdir/*_dynamic.o
echo "$shared compiled."
