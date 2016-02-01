#ifndef __DISPMAP_H__
#define __DISPMAP_H__

#include "sugoroku.h"
#include "player.h"
#include "position.h"
#include "map.h"

//int dispmap(Map* s, int x, int y, Player* p, int width, int height);
int dispmap(Map* m, int x, int y, Player* p, Position* pos, int width, int height);

#endif
