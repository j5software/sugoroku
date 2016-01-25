#include "item.h"

void initItem(Item *i) {
  i->name[0] = '\0';
  i->id = 0;
}

void useItem1() {
  //お金増やす
}

void useItem2() {
  //他のプレイヤーのお金を奪う
  //奪う対象をランダムにするか，選択にするか
}

void useItem3() {
  //スタートとゴールは逆にする
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
