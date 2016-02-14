#!/bin/sh

INC_DIR=/usr/include
LIB_DIR=/usr/lib

cp -v bin/libmurmur3.so "${LIB_DIR}"
cp -v src/murmur3.h "${INC_DIR}"

