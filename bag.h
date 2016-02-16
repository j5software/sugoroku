#ifndef __BAG_H__
#define __BAG_H__
#define BAG_SIZE 20

typedef struct BagItem {
  int item_id;
  int num; //個数
} BagItem;

typedef struct Bag
{
  // 1アイテム番号,2は個数
  BagItem *items;
  int size;
} Bag;

void initBag(Bag *b, int bag_size);
void deleteBag(Bag *b);
int addBagItem(Bag *b, int item_id, int num);
int popBagItem(Bag *b, int bag_num);

#endif
