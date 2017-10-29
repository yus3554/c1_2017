/**********************************
分析ファイル
2017/10/30
B15T2017C 太田悠介
***********************************/

#define GLOBAL_DEFINE
#include "lib1.h"

//問題の単語の品詞の状態を調べて配列に格納
void possearch(){
  for(int i = 0; i < quenum; i++){
    for(int j = 0; dict[j][0][0] != '\0'; j++){
      //単語と辞書の左側が一致している場合
      if(strcmp(questr[i], dict[j][0]) == 0){
        //単語の品詞に辞書の品詞をコピー
        strcpy(questrpos[i], dict[j][1]);
        break;
        //ピリオドが入っていた場合
      }else if(strcmp(questr[i], ".") == 0){
        //単語の品詞に"end"をコピー
        strcpy(questrpos[i], "end");
        break;
      }
    }
    //何とも一致しなかった場合配列には何も入っていないので
    if(strcmp(questrpos[i], "\0") == 0){
      printf("単語が辞書に存在していません.\n");
      exit(1);
    }
  }
}


//構造体を比較し、文法規則に則っていれば句を返す
//originが代入する構造体
//cellがそれぞれ比較する構造体
//return1で則っている
//return0で一致していなかった
int ckyana(ckycell *origin, ckycell *cell1, ckycell *cell2){
  for(int i = 0; i < SYNNUM; i++){
    for(int j = 0; j < 2; j++){
      for(int k = 0; k < 2; k++){
        //cell1と文法の真ん中が一致しているか
        if(strcmp((*cell1).pos[j], syn[i][1]) == 0){
          //文法の右が存在しているか
          if(syn[i][2][0] != '\0'){
            //存在している場合、それとcell2が一致しているか
            if(strcmp((*cell2).pos[k], syn[i][2]) == 0){
              //originのposに文法の左を代入
              //originのleft、rightにそれぞれcell1、cell2のポインタを代入
              //possuf0、1にそれぞれ構成するcell1とcell2の品詞の添え字を格納
              strcpy((*origin).pos[0], syn[i][0]);
              (*origin).left = cell1;
              (*origin).right = cell2;
              (*origin).possuf[0] = j;
              (*origin).possuf[1] = k;
              (*origin).num[0] = ckycellnum;
              return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}


void cky(){
  int flg = 0;
  for(int i = 2; i < quenum; i++){
    for(int j = 1; j < quenum + 1 - i; j++){
      for(int k = 1; k < i; k++){
        //flgが0ならckyanaを実行
        if(flg == 0){
          flg = ckyana(&ckyarray[j][j+i-1], &ckyarray[j][k+j-1], &ckyarray[k+j][i+j-1]);
        }
      }
      //flgをリセット
      flg = 0;
      //ckycellnumをカウント
      ckycellnum++;
    }
  }
}



//S式を表示する
void disp(ckycell *cell, int suf){
  //いれられたポインタがnullなら親に返す
  if(cell == NULL){
    return;
  }
  printf("(%s%d ", (*cell).pos[suf], (*cell).num[suf]);
  disp((*cell).left, (*cell).possuf[0]);
  //cellに単語が存在するならそれを表示
  if((*cell).word[0] != '\0'){
    if(suf == 0){
      printf("\"%s\"", (*cell).word);
    }else{
      printf("(%s \"%s\")", (*cell).pos[0], (*cell).word);
    }
  }
  disp((*cell).right, (*cell).possuf[1]);
  printf(")");
}
