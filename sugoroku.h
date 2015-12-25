#ifndef __SUGOROKU_H__
#define __SUGOROKU_H__
#include "item.h"
#include "map.h"
#include "player.h"

typedef struct Sugoroku {
  Player* player; // プレイヤー全員(配列)
  Map map;
  Item* item; // アイテムのリスト(配列)
  int player_num; // プレイヤーの人数
} Sugoroku;

void initSugoroku(Sugoroku* s, int player_num);
void sugorokuMain(Sugoroku* s);

#endif
