
//=============================================================================
// Contents   : 電気情報系実験3 C1 CKY法
//              cky法実行ファイル cky.c
// Author     : B15T2017C 太田悠介
// LastUpdate : 2017/10/30
// Since      : 2017/10/28
//=============================================================================


#define GLOBAL_DEFINE
#include "lib1.h"

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


//ckyanaをckyarray全てに対して実行させる
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
