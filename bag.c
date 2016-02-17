#include "bag.h"
#include <stdlib.h>

void initBag(Bag *b, int bag_size) {
  int i;
  b->size = bag_size;
  b->item = (BagItem *)malloc(sizeof(BagItem)*bag_size);
  for(i = 0; i < bag_size; i ++) {
    b->item[i].item_id = 0; // アイテム番号を格納する
    b->item[i].num = 0; // アイテム個数を格納する
  }
}

void deleteBag(Bag *b) {
  if(b->item)
    free(b->item);
}

int addBagItem(Bag *b, int item_id, int num) {
  int i;
  for(i = 0; i < b->size; i++) {
    if(b->item[i].item_id == item_id) {
      b->item[i].item_id = item_id;
      b->item[i].num += num;
      return 1;
    }
  }
  for(i = 0; i < b->size; i++) {
    if(b->item[i].num == 0) {
      b->item[i].item_id = item_id;
      b->item[i].num += num;
      return 1;
    }
  }
  return 0;
}

int popBagItem(Bag *b, int bag_num) {
  int i;
  if(bag_num < 0) {
    return -1;
  }
  if(b->item[bag_num].num <= 0) {
    return -1;
  }

  b->item[bag_num].num--;
  // 詰める
  if(b->item[bag_num].num <= 0) {
    for(i = bag_num; i < b->size-1; i++) {
      b->item[i] = b->item[i+1];
    }
  }
  return b->item[bag_num].item_id;
}
