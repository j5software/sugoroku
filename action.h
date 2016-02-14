#ifndef __ACTION_H__
#define __ACTION_H__
#include "menu.h"
#include "sugoroku.h"
#include "scene.h"

void panelEventAction(int current_key, Sugoroku *s, SugorokuStatus* ss, int player_id, Scene *scene);
void fieldAction(int current_key, Sugoroku *s, SugorokuStatus* ss, int player_id, MyMenu *menus, Scene *scene);
void selectAction(int current_key, Menu *m);
void moveAction(int current_key, Sugoroku *s, SugorokuStatus* ss, int player_id, Scene *scene);
int throwDice(double rate);
void throwDiceAction(int current_key, Sugoroku *s, SugorokuStatus* ss, int player_id, Scene* scene);

#endif
