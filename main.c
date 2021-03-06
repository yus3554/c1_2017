
//=============================================================================
// Contents   : 電気情報系実験3 C1 CKY法
//              メインファイル main.c
// Author     : B15T2017C 太田悠介
// LastUpdate : 2017/10/30
// Since      : 2017/10/28
//=============================================================================


//コマンドライン引数で辞書ファイルの指定をする
//以下の例は課題1を指定したものである
//例) $./ex1 dict1.txt syn1.txt que1.txt

#define GLOBAL_DEFINE
#include "lib1.h"

int main(int argc, char* argv[]){

  //初期化
  //コマンドライン引数の第一変数を渡す
  //argv[1]:辞書ファイル
  //argv[2]:文法ファイル
  //argv[3]:英文ファイル
  inimain(argv[1], argv[2], argv[3]);

  //cky実行
  cky();

  //S式を表示
  //入れている配列は表の右上のcell
  expdisp(&ckyarray[1][quenum-1], 0);
  printf("\n");

  //表の表示
  tabledisp();

  return 0;
}
