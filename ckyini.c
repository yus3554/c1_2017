
//=============================================================================
// Contents   : 電気情報系実験3 C1 CKY法
//              ckyarray初期化ファイル ckyini.c
// Author     : B15T2017C 太田悠介
// LastUpdate : 2017/10/30
// Since      : 2017/10/28
//=============================================================================


#define GLOBAL_DEFINE
#include "lib1.h"

//ckycellを初期化する
//単語と品詞を代入し、句を入れれるなら入れる
void ckyini(){
  ckycellnum = 1;
  for(int i = 1; i < quenum; i++){
    //ckyarrayのwordに単語を代入
    strcpy(ckyarray[i][i].word, questr[i-1]);
    //ckyarrayのpos[0]に品詞を代入
    strcpy(ckyarray[i][i].pos[0], questrpos[i-1]);
    //numにckycellnumを代入
    ckyarray[i][i].num[0] = ckycellnum;
    //さらに句がある場合はpos[1]に代入
    ckykuini(&ckyarray[i][i]);
    //ckycellnumをカウント
    ckycellnum++;
  }
}

//品詞をいれて、句もあるなら代入
void ckykuini(ckycell *cell){
  for(int i = 0; i < SYNNUM; i++){
    //ckyiniで先に格納された品詞(pos[0])と文法の真ん中を比較、さらに文法の右が存在していない場合
    if((strcmp((*cell).pos[0], syn[i][1]) == 0) && syn[i][2][0] == '\0'){
      //pos[1]に文法の左を代入
      strcpy((*cell).pos[1], syn[i][0]);
      (*cell).num[1] = ckycellnum;
    }
  }
}
