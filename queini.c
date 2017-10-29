
//=============================================================================
// Contents   : 電気情報系実験3 C1 CKY法
//              問題文入力ファイル queini.c
// Author     : B15T2017C 太田悠介
// LastUpdate : 2017/10/30
// Since      : 2017/10/28
//=============================================================================


#define GLOBAL_DEFINE
#include "lib1.h"

//問題文を配列に入力し、空白ごとに2次元配列に格納し、単語数を返す
int queini(char filename[]){
  char que[100] = {}; //問題文入力用配列
  FILE *fp;
  int k = 0; //単語分け用の添字

  if ((fp = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "%sのオープンに失敗しました.\n", filename);
    exit(EXIT_FAILURE);
  }

  fscanf(fp, "%[^\n]", que);

  printf("解析文 : %s\n", que);

  //que[i]が'\0'になるまでループ
  for(int i = 0, j = 0; que[i] != '\0'; i++){
    //que[i]が空白orピリオドで無いならば
    if(que[i] != ' ' && que[i] != '.'){
      //questrに1文字コピーする
      questr[k][j] = que[i];
      j++;
      //ピリオドならば
    }else if(que[i] == '.'){
      //k++して配列を1個ずらしてピリオドを追加
      k++;
      questr[k][0] = '.';
      //空白ならば
    }else{
      //k++
      j = 0;
      k++;
    }
  }

  return k+1;
}
