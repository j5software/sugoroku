#include "bag.h"
#include <stdlib.h>

void initBag(Bag *b, int bag_size) {
  int i;
  b->size = bag_size;
  b->items = (BagItem *)malloc(sizeof(BagItem)*bag_size);
  for(i = 0; i < bag_size; i ++) {
    b->items[i].item_id = 0; // アイテム番号を格納する
    b->items[i].num = 0; // アイテム個数を格納する
  }
}

void deleteBag(Bag *b) {
  if(b->items)
    free(b->items);
}

int addBagItem(Bag *b, int item_id, int num) {
  int i;
  for(i = 0; i < b->size; i++) {
    if(b->items[i].item_id == item_id) {
      b->items[i].item_id = item_id;
      b->items[i].num++;
      return 1;
    }
  }
  for(i = 0; i < b->size; i++) {
    if(b->items[i].num == 0) {
      b->items[i].item_id = item_id;
      b->items[i].num++;
      return 1;
    }
  }
  return 0;
}

int popBagItem(Bag *b, int bag_num) {
  int i;
  if(b->items[bag_num].num <= 0) {
    return -1;
  }

  b->items[bag_num].num--;
  // 詰める
  if(b->items[bag_num].num <= 0) {
    for(i = bag_num; i < b->size-1; i++) {
      b->items[i] = b->items[i+1];
    }
  }
  return b->items[bag_num].item_id;
}
