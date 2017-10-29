#!/bin/sh

#B15T2017C 太田悠介
#C1のシェルスクリプト

echo 課題の番号は?
read kadainum

#make clean
make
./ex1 dict${kadainum}.txt syn${kadainum}.txt que${kadainum}.txt
