/***************************
辞書ファイルを読み込んだり問題文を入力させる初期化用ファイル

2017/10/30
B15T2017C 太田悠介
***************************/

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
