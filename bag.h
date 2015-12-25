#ifndef __BAG_H__
#define __BAG_H__

typedef struct Bag
{
  // 1アイテム番号,2は個数
  int items[20][2];
} Bag;

void initBag(Bag* b);

#endif
