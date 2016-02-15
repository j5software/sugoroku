#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "bag.h"
#include "position.h"

typedef struct Player {
  int player_num;
  char name[20];
  int money;
  int is_goal;
  int ranking;
  Bag bag;    //change name
  Position pos;
  PositionList footmark;
} Player;

void initPlayer(Player *p, int player_num);

#endif
