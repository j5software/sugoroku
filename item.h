#ifndef __ITEM_H__
#define __ITEM_H__
#include "scene.h"
#include "position.h"

struct Sugoroku;
struct SugorokuStatus;
struct DispOption;

typedef struct Item
{
  int id;
  char name[20];
  int hastarget;
  void (*use)(struct Sugoroku *s, struct SugorokuStatus *ss, int player_id, int target, Scene *scene);
} Item;

void initItem(Item *i);
void dummy_use(struct Sugoroku *s, struct SugorokuStatus *ss, int player_id, int target, Scene *scene);

#endif
