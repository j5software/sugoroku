#ifndef __ACTION_H__
#define __ACTION_H__
#define ADD_MONEY 200
#define BONUS_COIN 1000
#include "menu.h"
#include "sugoroku.h"
#include "scene.h"
#include "position.h"

void backPlayer(Sugoroku *s, SugorokuStatus* ss, int player_id, int backnum);
void itemMenuAction(int current_key, Sugoroku *s, SugorokuStatus* ss, int player_id, MyMenu *menus, Scene* scene);
void panelEventAction(int current_key, Sugoroku *s, SugorokuStatus* ss, int player_id, Scene *scene);
void fieldAction(int current_key, Sugoroku *s, SugorokuStatus* ss, int player_id, MyMenu *menus, Scene *scene);
void selectAction(int current_key, Menu *m);
void selectTargetAction(int current_key, Sugoroku *s, SugorokuStatus* ss, int player_id, MyMenu *menus, Scene* scene);
void shopAction(int current_key, Sugoroku *s, SugorokuStatus* ss, int player_id, MyMenu *menus, Scene* scene);
void moveAction(int current_key, Sugoroku *s, SugorokuStatus* ss, int player_id, Scene *scene);
int throwDice(double rate);
void throwDiceAction(int current_key, Sugoroku *s, SugorokuStatus* ss, int player_id, Scene* scene);
void useItem(Sugoroku *s, SugorokuStatus* ss, int player_id, int target, int item_id);
void useItemAction(int current_key, Sugoroku *s, SugorokuStatus* ss, int player_id, Scene* scene);
void resultAction(int current_key, Sugoroku *s, SugorokuStatus* ss, int player_id, Scene* scene);

#endif
