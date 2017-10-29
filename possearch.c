
//=============================================================================
// Contents   : 電気情報系実験3 C1 CKY法
//              単語の品詞検索ファイル possearch.c
// Author     : B15T2017C 太田悠介
// LastUpdate : 2017/10/30
// Since      : 2017/10/28
//=============================================================================


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
