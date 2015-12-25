#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "bag.h"

typedef struct Position {
  int x;
  int y;
} Position;


typedef struct Player {
  int player_num;
  char name[20];
  int money;
  Bag bag;    //change name
  Position pos;
} Player;

void initPlayer(Player *p, int player_num);

#endif
