#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "bag.h"

typedef struct position
{
  int x;
  int y;
} position;


typedef struct player
{
  int num;
  char name[20];
  int money;
  bag _bag;    //change name
  position pos;
} player;

void initPlayer(player *p);

#endif
