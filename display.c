
//=============================================================================
// Contents   : 電気情報系実験3 C1 CKY法
//              S式や表の表示ファイル display.c
// Author     : B15T2017C 太田悠介
// LastUpdate : 2017/10/30
// Since      : 2017/10/28
//=============================================================================


#define GLOBAL_DEFINE
#include "lib1.h"

//S式を表示する
//sufはposやnumの添え字
void expdisp(ckycell *cell, int suf){
  //いれられたポインタがnullなら親に返す
  if(cell == NULL){
    return;
  }
  printf("(%s%d ", (*cell).pos[suf], (*cell).num[suf]);
  expdisp((*cell).left, (*cell).possuf[0]);
  //cellに単語が存在するならそれを表示
  if((*cell).word[0] != '\0'){
    if(suf == 0){
      printf("\"%s\"", (*cell).word);
    }else{
      printf("(%s \"%s\")", (*cell).pos[0], (*cell).word);
    }
  }
  expdisp((*cell).right, (*cell).possuf[1]);
  printf(")");
}

//CKY法の表を表示する
void tabledisp(){
  char temp[20] = {};
  char numnum[10];
  printf("-");
  for(int j = 1; j < quenum; j++){
    printf("-------------");
  }
  printf("\n");
  for(int i = 1; i < quenum; i++){
    for(int j = 1; j < quenum; j++){
      if(j >= i){
        printf("|%12s", ckyarray[i][j].word);
      }else{
        printf("%13s", " ");
      }
    }
    printf("|\n");
    for(int j = 1; j < quenum; j++){
      if(j >= i){
        strcpy(temp, ckyarray[i][j].pos[0]);
        if(ckyarray[i][j].num[0] != 0){
          sprintf(numnum, "%d", ckyarray[i][j].num[0]);
          strcat(temp, numnum);
        }
        if(ckyarray[i][j].pos[1][0] != '\0'){
          strcat(temp, "/");
          strcat(temp, ckyarray[i][j].pos[1]);
          sprintf(numnum, "%d", ckyarray[i][j].num[0]);
          strcat(temp, numnum);
        }
        printf("|%12s", temp);
      }else{
        printf("%13s", " ");
      }
    }
    printf("|\n");
    for(int j = 1; j < quenum; j++){
      if(j >= i){
        if(ckyarray[i][j].left != NULL){
          strcpy(temp, "(");
          strcat(temp, ckyarray[i][j].left->pos[ckyarray[i][j].possuf[0]]);
          sprintf(numnum, "%d", ckyarray[i][j].left->num[ckyarray[i][j].possuf[0]]);
          strcat(temp, numnum);
          strcat(temp, ",");
          strcat(temp, ckyarray[i][j].right->pos[ckyarray[i][j].possuf[1]]);
          sprintf(numnum, "%d", ckyarray[i][j].right->num[ckyarray[i][j].possuf[1]]);
          strcat(temp, numnum);
          strcat(temp, ")");
          printf("|%12s", temp);
        }else{
          printf("|%12s", " ");
        }
      }else{
        printf("%13s", "");
      }
    }
    printf("|\n");
    for(int j = 1; j < quenum; j++){
      if(j >= i){
        printf("-------------");
      }else{
        printf("%13s", " ");
      }
    }
    printf("-\n");
  }
}
