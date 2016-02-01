#include "item.h"

#include <stdlib.h>

void initItem(Item *i) {
  i->name[0] = '\0';
  i->id = 0;
}

void useItem1(Player *p, int player_num) {
  //おこづかい：お金増やす
  int get_money;
  get_money = (rand()%10 + 1) * 1000;
  p[player_num].money += get_money;
  printw("%sの所持金が%d円増えた．\n", p[player_num].name, get_money);
}

void useItem2(Player *p, int get_player, int player_maxnum) {
  //ごうだつ：ランダムに他のプレイヤーのお金を三割を奪う
  while (1) {
    int stolen_player; //お金を奪われるプレイヤーの番号
    int stolen_money;  //プレイヤーの奪われるお金（所持金の三割）
    stolen_player = rand()%player_maxnum;
    if (stolen_player != get_player) {
      stolen_money = p[stolen_player].money * 0.3;
      p[stolen_player].money -= stolen_money;
      p[get_player].money += stolen_money;
      printw("%sが%sから%d円奪った！\n", p[get_player].name, p[stolen_player].name, stolen_money);
      printw("%sの所持金は%d円減った．\n", p[stolen_player].name, stolen_money);
      printw("%sの所持金は%d円増えた．\n", p[get_player].name, stolen_money);
      break;
    }
  }
}

void useItem3() {
  //ぎゃくてんスイッチ：スタートとゴールを逆にする
  //プレイヤーの進む方向を変更する
}

void useItem4(Player *p, int player_num) {
  //選択したプレイヤーと場所を交換する
  int change_player;
  printw("%sさん，どのプレイヤーと位置を交換しますか？\n", p[player_num].name);
  printw("交換したいプレイヤー番号を入力してください．\n");
  scanw("%d", &change_player);
  changePosition(p, player_num, change_player);
  printw("%sさんと%sさんの位置を交換しました．\n", p[player_num].name, p[change_player].name);
}

void useItem5(Player *p, int player_maxnum) {
  //全部のプレイヤーの場所をシャッフル
  int i;
  int num1, num2;
  for (i = 0; i < 10; i++) {
    num1 = rand()%player_maxnum;
    num2 = rand()%player_maxnum;
    changePosition(p, num1, num2);
  }
  printw("全員の位置をシャッフルしました．\n");
}

void useItem6() {
  //SHOPのマスじゃないけどSHOPを開く
}

void useItem7(double *rate) {
  //サイコロの出た目を2倍にする
  *rate = 2.0;
}

void useItem8() {
  //他のプレイヤーを1回休みにする
}

void useItem9(Player　*p) {
  //お金を払った分だけマスを進む
  int pay_money;
  printw("お金を払った分だけ進むことができます．(最大5マス)");
  scanw("%d", &pay_money);
  p->money -= pay_money;
  //あとまわし
}

void useItem10() {
  //ランダムでアイテム使用
}

void changePosition(Player *p, int num1, int num2) {
  Position tmp;
  tmp.x = p[num1].pos.x;
  tmp.y = p[num1].pos.y;
  p[num1].pos.x = p[num2].pos.x;
  p[num1].pos.y = p[num2].pos.y;
  p[num2].pos.x = tmp.x;
  p[num2].pos.y = tmp.y;
}
