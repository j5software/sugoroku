#include "useItem.h"
#include <ncurses.h>
#include <stdlib.h>

void useItem0(Sugoroku *s, SugorokuStatus *ss, int player_id, int target) {
  //おこづかい：お金増やす
  int get_money;
  get_money = (rand()%10 + 1) * 1000;
  s->player[target].money += get_money;
  //printw("%sの所持金が%d円増えた．\n", p[player_num].name, get_money);
}

void useItem1(Sugoroku *s, SugorokuStatus *ss, int player_id, int target) {
  //ごうだつ：他のプレイヤーのお金を三割を奪う
  int stolen_money;  //プレイヤーの奪われるお金（所持金の三割）
  stolen_money = s->player[target].money * 0.3;
  s->player[target].money -= stolen_money;
  s->player[player_id].money += stolen_money;
  /*
     printw("%sが%sから%d円奪った！\n", p[get_player].name, p[stolen_player].name, stolen_money);
     printw("%sの所持金は%d円減った．\n", p[stolen_player].name, stolen_money);
     printw("%sの所持金は%d円増えた．\n", p[get_player].name, stolen_money);*/
}

void useItem2(Sugoroku *s, SugorokuStatus *ss, int player_id, int target) {
  //ぎゃくてんスイッチ：スタートとゴールを逆にする
  //プレイヤーの進む方向を変更する
}

void useItem3(Sugoroku *s, SugorokuStatus *ss, int player_id, int target) {
  //選択したプレイヤーと場所を交換する
  changePosition(s->player, player_id, target);
  //printw("%sさんと%sさんの位置を交換しました．\n", p[player_num].name, p[change_player].name);
}

void useItem4(Sugoroku *s, SugorokuStatus *ss, int player_id, int target) {
  //全部のプレイヤーの場所をシャッフル
  int i;
  int num2;
  for (i = 0; i < s->player_num; i++) {
    num2 = rand()%s->player_num;
    changePosition(s->player, i, num2);
  }
  //printw("全員の位置をシャッフルしました．\n");
}

void useItem5(Sugoroku *s, SugorokuStatus *ss, int player_id, int target) {
  //SHOPのマスじゃないけどSHOPを開く
}

void useItem6(Sugoroku *s, SugorokuStatus *ss, int player_id, int target) {
  //サイコロの出た目を2倍にする
  ss->dice_rate[target] = 2.0;
}

void useItem7(Sugoroku *s, SugorokuStatus *ss, int player_id, int target) {
  //他のプレイヤーを1回休みにする
}

void useItem8(Sugoroku *s, SugorokuStatus *ss, int player_id, int target) {
  //お金を払った分だけマスを進む
  // めんどいからやめる
  /*
  int pay_money;
  printw("お金を払った分だけ進むことができます．(最大5マス)");
  scanw("%d", &pay_money);
  p->money -= pay_money;*/
  //あとまわし
}

void useItem9(Sugoroku *s, SugorokuStatus *ss, int player_id, int target) {
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
