#ifndef __BASS_H__
#define __BASS_H__
#include "bag.h"
#include "player.h"

int throwDice(void);
void movePlayer(Player *p, Map *m);
void openBag(void);
void openMenu(void);
void selectMenu(void);
void save(void);
void load(void);


#endif
