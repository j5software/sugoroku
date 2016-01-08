#ifndef __ITEM_H__
#define __ITEM_H__

typedef struct Item
{
  int id;
  char name[20];
} Item;

void initItem(Item *i);

#endif
