#ifndef __ITEM_H__
#define __ITEM_H__

typedef struct Item
{
  char name[20];
  int id;
} Item;

void initItem(Item *i);

#endif
