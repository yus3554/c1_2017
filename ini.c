
//=============================================================================
// Contents   : 電気情報系実験3 C1 CKY法
//              初期化メインファイル ini.c
// Author     : B15T2017C 太田悠介
// LastUpdate : 2017/10/30
// Since      : 2017/10/28
//=============================================================================


#include "lib1.h"

//初期化のメイン
void inimain(char dictname[], char synname[], char filename[]){
  dictini(dict, dictname);
  synini(syn, synname);
  //quenumに単語数を代入
  quenum = queini(filename);
  possearch();
  ckyini();
}
