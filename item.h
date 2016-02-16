#ifndef __ITEM_H__
#define __ITEM_H__

#include "player.h"
#include "position.h"

struct Sugoroku;
struct SugorokuStatus;

typedef struct Item
{
  int id;
  char name[20];
  void (*use)(struct Sugoroku *s, struct SugorokuStatus *ss, int player_id, int target);
} Item;

void initItem(Item *i);
void dummy_use(struct Sugoroku *s, struct SugorokuStatus *ss, int player_id, int target);

#endif
