#!bin/bash

DIR=$1

clang++ -std=c++11 -stdlib=libc++ $DIR/source.cpp && ./a.out
