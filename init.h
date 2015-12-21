#ifndef __INIT_H__
#define __INIT_H__
#include "item.h"
#include "map.h"
#include "player.h"
#include <ncurses.h>

void initItem(item *p);
void inputName(player *p);
void initCurses();

#endif
