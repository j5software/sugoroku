#ifndef __SUGOROKU_H__
#define __SUGOROKU_H__
#include "item.h"
#include "map.h"
#include "player.h"
#include "useItem.h"
#include "shop.h"

typedef struct Sugoroku {
  Player* player; // プレイヤー全員(配列)
  Map map;
  Item* item; // アイテムのリスト(配列)
  Shop shop; // ショップ
  int item_num; // アイテムの種類の数
  int player_num; // プレイヤーの人数
} Sugoroku;

typedef struct SugorokuStatus {
  int current_player;
  int move_num; // 動かせる回数
  int goal_player_num;
  int select_itemid;
  int select_bag;
  int item_target;
  double *dice_rate;
  PositionList plist;
} SugorokuStatus;

int initSugoroku(Sugoroku *s, int player_num);
void initSugorokuStatus(SugorokuStatus *ss, Sugoroku *s);
int finalizeSugoroku(Sugoroku *s);
void finalizeSugorokuStatus(SugorokuStatus *ss);
int importItemFile(Sugoroku *sugoroku, char *dir);
int canMove(Map *m, Position p);
int movePlayer(Sugoroku *, int player_id, enum Direction d, PositionList*, SugorokuStatus *ss);
int setNextPlayer(Sugoroku *s, SugorokuStatus *ss);
int setPlayerStart(Sugoroku *s);

#endif
