#! /usr/bin/env bash
# Copyright 2020 @bynect
# This is free and open source software.
# You can use/modify/redistribute it under the terms of the MIT license.
# See docs/LICENSE for for more details.

set -e

libdir=${libdir:-"./lib"}
objdir=${objdir:-"$libdir/obj"}

static=${static:-"$libdir/libbasex.a"}
shared=${shared:-"$libdir/libbasex.so"}

testfile=${testfile:-"./etc/basex_test"}

#remove libs and objects
rm -f $objdir/*.o
rm -f $static $shared
rm -f $testfile
