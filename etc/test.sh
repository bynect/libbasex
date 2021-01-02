#! /usr/bin/env bash
# Copyright 2020-2021 @bynect
# This is free and open source software.
# You can use/modify/redistribute it under the terms of the MIT license.
# See docs/LICENSE for for more details.

libdir=${libdir:-"./lib"}
incdir=${incdir:-"./include"}

static=${static:-"$libdir/libbasex.a"}
shared=${shared:-"$libdir/libbasex.so"}

#compile library
./${libsh:-"./etc/lib.sh"}

cc=gcc
cflags="-g -ansi -L$libdir -I$incdir"

#compile tests
testfile=${testfile:-"./etc/basex_test"}

$cc "$testfile.c" -o "$testfile" $cflags $static

#run tests
if ./"$testfile"; then
    echo "All tests passed. Exiting."
else
    echo "A test failed. Aborting."
fi
