#ifndef __ITEM_H__
#define __ITEM_H__

#include "player.h"
#include "position.h"

typedef struct Item
{
  int id;
  char name[20];
} Item;

void initItem(Item *i);
void useItem1(Player *p, int player_num);
void useItem2(Player *p, int get_player, int player_maxnum);
void useItem3();
void useItem4(Player *p, int player_num);
void useItem5(Player *p, int player_maxnum);
void useItem6();
void useItem7();
void useItem8();
void useItem9();
void useItem10();
void changePosition(Player *p, int num1, int num2);

#endif
