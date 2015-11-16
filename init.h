#ifndef __INIT_H__
#define __INIT_H__
#include "map.h"
#include "player.h"

typedef struct item
{
  char name[20];
} item;




void initItem(item *p);
void inputName(player *p);

#endif
