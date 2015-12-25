#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "bag.h"

typedef struct Position {
  int x;
  int y;
} Position;


typedef struct Player {
  int num;
  char name[20];
  int money;
  Bag bag;    //change name
  Position pos;
} Player;

void initPlayer(Player *p);

#endif
