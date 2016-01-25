#include "bag.h"

void initBag(Bag* b) {
  int i;
  for(i = 0; i < 20; i ++) {
    b->items[i][0] = -1; //-1で何も持ってない　アイテム番号を格納する
    b->items[i][1] = -1; //-1で何も持ってない　アイテム個数を格納する
  }
}
