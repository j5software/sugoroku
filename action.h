#ifndef __ACTION_H__
#define __ACTION_H__
#include "menu.h"
#include "sugoroku.h"

void selectAction(int current_key, Menu *m);
void moveAction(int current_key, Sugoroku *s, SugorokuStatus* ss, int player_id);

#endif
