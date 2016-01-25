#include "item.h"

#include <stdlib.h>
#include <time.h>

void initItem(Item *i) {
  i->name[0] = '\0';
  i->id = 0;
}

void useItem1(Player *p, int player_num) {
  //お金増やす
  srand((unsigned)time(NULL));
  int num;
  num = rand()%10 + 1;
  p[player_num].money += 1000*num;
}

void useItem2(Player *p, int get_player, int player_maxnum) {
  //ランダムに他のプレイヤーのお金を三割を奪う
  srand((unsigned)time(NULL));
  while (1) {
    int stolen_player; //お金を奪われるプレイヤーの番号
    int stolen_money;  //プレイヤーの奪われるお金（所持金の三割）
    stolen_player = rand()%player_maxnum;
    if (stolen_player != get_player) {
      stolen_money = p[stolen_player].money * 0.3;
      p[stolen_player].money -= stolen_money;
      p[get_player].money += stolen_money;
      break;
    }
  }
}

void useItem3() {
  //スタートとゴールを逆にする
}

void useItem4() {
  //選択したプレイヤーと場所を交換する
}

void useItem5() {
  //全部のプレイヤーの場所をシャッフル
}

void useItem6() {
  //SHOPのマスじゃないけどSHOPを開く
}

void useItem7() {
  //サイコロの出た目を二倍，もしくはサイコロを2個にする
}

void useItem8() {
  //他のプレイヤーを1回休みにする
}

void useItem9() {
   //ランダムでアイテム使用
}

void useItem10() {
  //お金を払った分だけマスを進む
}
