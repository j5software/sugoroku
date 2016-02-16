#ifndef __DISP_H__
#define __DISP_H__
#define MASU_W 5 // マスの表示上の幅
#define MASU_H 4 // マスの表示上の高さ
#include "scene.h"
#include "sugoroku.h"
#include "menu.h"

typedef struct DispOption {
  int std_x, std_y; // 表示の基準の位置
  int map_w, map_h; // 表示するマップの幅と高さ
  int mes_x, mes_y; // メッセージとかの表示位置
  int menu_x, menu_y; // ルートメニューの位置
} DispOption;

void initDispOption(DispOption *doption);
void dispField(Sugoroku *s, SugorokuStatus *ss, MyMenu *mymenu, DispOption *doption);
void dispItemMenu(Sugoroku *s, SugorokuStatus *ss, MyMenu *mymenu, DispOption *doption);
int dispmap(Map* m, Player p[], int player_num, int x, int y, Position pos, int width, int height);
int dispmenu(Menu* m, int x, int y);
void dispMove(SugorokuStatus *ss, DispOption *doption);
void dispThrowDice(SugorokuStatus *ss, DispOption *doption);
void dispResult(Sugoroku *s, SugorokuStatus *ss, Scene scene, DispOption *doption);
void dispSelectTarget(Sugoroku *s, SugorokuStatus *ss, MyMenu *mymenu, DispOption *doption);
void dispUseItem(Sugoroku *s, SugorokuStatus *ss, Scene scene, DispOption *doption);
int display(Sugoroku *sugoroku, SugorokuStatus *ss, MyMenu *mymenu, Scene scene, DispOption *doption);

#endif
