
//=============================================================================
// Contents   : 電気情報系実験3 C1 CKY法
//              辞書、文法規則初期化ファイル dictionaryini.c
// Author     : B15T2017C 太田悠介
// LastUpdate : 2017/10/30
// Since      : 2017/10/28
//=============================================================================


#define GLOBAL_DEFINE
#include "lib1.h"

//別ファイルに保存してある辞書を格納
void dictini(char array[][2][10],  char dictname[]){
  FILE *fp;

  if ((fp = fopen(dictname, "r")) == NULL) {
    fprintf(stderr, "%sのオープンに失敗しました.\n", dictname);
    exit(EXIT_FAILURE);
  }

  //辞書ファイルから空白ごとに配列に格納
  int i = 0;
  while (fscanf(fp, "%s%s", array[i][0], array[i][1]) != EOF){
    i++;
  }
}


//別ファイルに保存してある辞書を格納
void synini(char array[][3][10],  char synname[]){
  FILE *fp;
  char *ch;
  char temp[100] = {};

  if ((fp = fopen(synname, "r")) == NULL) {
    fprintf(stderr, "%sのオープンに失敗しました.\n", synname);
    exit(EXIT_FAILURE);
  }

  //文法ファイルから空白ごとに配列に格納
  int i = 0, k = 0;
  while (fscanf(fp, "%s", temp) != EOF){
    k = 0;
    //コンマごとに配列に格納
    ch = strtok(temp, ",");
    strcpy(array[i][0], ch);
    while(ch != NULL){
      k++;
      ch = strtok(NULL, ",");
      if(ch != NULL){
        strcpy(array[i][k], ch);
      }
    }
    i++;
  }
}
