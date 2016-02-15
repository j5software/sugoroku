#include "player.h"

void initPlayer(Player *p, int player_num) {
  p->player_num = player_num;
  p->name[0] = '\0';
  p->money = 0;
  p->pos.x = p->pos.y = 0;
  p->is_goal = 0;
  p->ranking = 1;

  initBag(&p->bag);
  initPositionList(&p->footmark);
}
