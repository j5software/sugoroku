#ifndef __INIT_H__
#define __INIT_H__
#include "map.h"

typedef struct position
{
  int x;
  int y;
} position;

typedef struct bag
{
  int items[20];
} bag;

typedef struct item
{
  char name[20];
} item;




void initItem(item *p);
void inputName(player *p);

#endif
