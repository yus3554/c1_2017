
//=============================================================================
// Contents   : 電気情報系実験3 C1 CKY法
//              ヘッダファイル lib1.h
// Author     : B15T2017C 太田悠介
// LastUpdate : 2017/10/30
// Since      : 2017/10/28
//=============================================================================


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//定数
#define SYNNUM 20  //文法の数
#define WORDNUM 20 //単語数

//構造体の宣言
typedef struct CKY{
  char word[10]; //単語
  char pos[2][10]; //品詞、句
  int num[2]; //DET1やNOUN5などの1や5の数字
  //num[0]には普通の品詞や句が入っている
  //num[1]には例えばNOUNとNPなど1単語で品詞と句が入っている場合に句が入っている

  int possuf[2]; //arraysufのposの添え字(VERBなのかVPなのかなどの判別)
  //possuf[0]がleftの添え字と対応
  //possuf[1]がrightの添え字と対応

  //自己参照ポインタ
  struct CKY *left;
  struct CKY *right;
} ckycell;


//グローバル変数
//GLOBAL_DEFINEが定義されていれば
#ifdef GLOBAL_DEFINE
//GLOBALは空白
#define GLOBAL
//定義されていなければ
#else
//GLOBALはexternに変化
#define GLOBAL extern
#endif
//これにより多重定義を回避

GLOBAL char questr[WORDNUM][10]; //問題文が単語ごとに格納 [単語数][文字数]
GLOBAL char questrpos[WORDNUM][10]; //問題文の単語の品詞を格納

GLOBAL char dict[WORDNUM][2][10]; //辞書が格納 [単語数][][文字数]
GLOBAL char syn[SYNNUM][3][10]; //文法が格納

GLOBAL int quenum; //問題の単語数を格納

GLOBAL ckycell ckyarray[10][10]; //ckycellのn*nの配列[n][n]

GLOBAL int ckycellnum; //ckycellのnumに使う


//プロトタイプ宣言

void tabledisp();
void inimain(char dictname[], char synname[], char filename[]);
void dictini(char array[][2][10],  char dictname[]);
void synini(char array[][3][10],  char synname[]);
int queini(char filename[]);
void ckyini();
void ckykuini(ckycell *cell);
void possearch();
int ckyana(ckycell *origin, ckycell *cell1, ckycell *cell2);
void cky();
void expdisp(ckycell *cell, int suf);
