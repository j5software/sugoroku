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

typedef struct player
{
  int num;
  char name[20];
  int money;
  bag _bag;    //change name
  position pos;
} player;



void initPlayer(player *p);
void initItem(item *p);
void inputName(player *p);

#endif
