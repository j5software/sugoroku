#ifndef __SUGOROKU_H__
#define __SUGOROKU_H__
#include "item.h"
#include "menu.h"
#include "map.h"
#include "player.h"

typedef struct Sugoroku {
  Player* player; // プレイヤー全員(配列)
  Map map;
  Item* item; // アイテムのリスト(配列)
  int item_num; // アイテムの種類の数
  int player_num; // プレイヤーの人数
} Sugoroku;

void initSugoroku(Sugoroku* s, int player_num);
void importItemFile(Sugoroku* sugoroku);
void initMainMenu(Menu* main_menu);

#endif
