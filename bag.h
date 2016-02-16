#ifndef __BAG_H__
#define __BAG_H__
#define BAG_SIZE 20

typedef struct Bag
{
  // 1アイテム番号,2は個数
  int items[BAG_SIZE][2];
} Bag;

void initBag(Bag* b);

#endif
