#ifndef __ITEM_H__
#define __ITEM_H__


typedef struct item
{
  char name[20];
  int id;
} item;

extern item* items;

#endif
