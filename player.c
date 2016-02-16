#include "player.h"

void initPlayer(Player *p, int player_id) {
  p->player_id = player_id;
  p->name[0] = '\0';
  p->money = 0;
  p->pos.x = p->pos.y = 0;
  p->is_goal = 0;
  p->ranking = 1;

  initBag(&p->bag, BAG_SIZE);
  initPositionList(&p->footmark);
}

void finalizePlayer(Player *p) {
  deleteBag(&p->bag);
}
