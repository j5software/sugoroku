#ifndef __DISP_H__
#define __DISP_H__
#define MASU_W 5 // マスの表示上の幅
#define MASU_H 4 // マスの表示上の高さ
#include "scene.h"
#include "sugoroku.h"
#include "menu.h"
#include "dispOption.h"

void initDispOption(DispOption *doption);
void dispField(Sugoroku *s, SugorokuStatus *ss, MyMenu *mymenu, DispOption *doption);
void dispItemMenu(Sugoroku *s, SugorokuStatus *ss, MyMenu *mymenu, DispOption *doption);
int dispmap(Map* m, Player p[], int player_num, int x, int y, Position pos, int width, int height);
int dispmenu(Menu* m, int x, int y);
void dispMove(SugorokuStatus *ss, DispOption *doption);
void dispPanelEffect(Sugoroku *s, SugorokuStatus *ss, int item_id, DispOption *doption);
void dispPlayerStatus(Sugoroku *s, SugorokuStatus *ss, MyMenu *mymenu, DispOption *doption);
void dispThrowDice(SugorokuStatus *ss, DispOption *doption);
void dispResult(Sugoroku *s, SugorokuStatus *ss, Scene scene, DispOption *doption);
void dispSelectTarget(Sugoroku *s, SugorokuStatus *ss, MyMenu *mymenu, DispOption *doption);
void dispShop(Sugoroku *s, SugorokuStatus *ss, MyMenu *mymenu, DispOption *doption);
void dispUseItem(Sugoroku *s, SugorokuStatus *ss, Scene scene, DispOption *doption);
int display(Sugoroku *sugoroku, SugorokuStatus *ss, MyMenu *mymenu, Scene scene, DispOption *doption);

#endif
