/****************************:
メインファイル
2017/10/30
B15T2017C 太田悠介
*****************************/

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

  cky();

  disp(&ckyarray[1][quenum-1], 0);
  printf("\n");

  test();

  return 0;
}

void test(){
  //////////////////////////////////////////試しに表示
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
