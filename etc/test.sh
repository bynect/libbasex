#! /usr/bin/env bash
# Copyright 2020 @bynect
# This program is free and open source software.
# You can use/modify/redistribute it under the terms of the MIT license.
# See etc/LICENSE for for more details.

testdir=${testdir:-"./test"}
libdir=${libdir:-"./lib"}
incdir=${incdir:-"./include"}

static=${static:-"$libdir/libbasex.a"}
shared=${shared:-"$libdir/libbasex.so"}

#compile library
./${libsh:-"./etc/lib.sh"}

cc=gcc
cflags="-g -ansi -L$libdir -I$incdir"

#compile tests
$cc $testdir/*.c -o $testdir/basex_test $cflags $static

#run tests
if ./$testdir/basex_test; then
    echo "All tests passed. Exiting."
else
    echo "A test failed. Aborting."
fi
