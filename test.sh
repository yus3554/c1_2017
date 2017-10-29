#!/bin/sh

#=============================================================================
# Contents   : 電気情報系実験3 C1 CKY法
#              シェルファイル
# Author     : B15T2017C 太田悠介
# LastUpdate : 2017/10/30
# Since      : 2017/10/28
#=============================================================================

echo 課題の番号は?
read kadainum

#make clean
make
./ex1 dict${kadainum}.txt syn${kadainum}.txt que${kadainum}.txt
