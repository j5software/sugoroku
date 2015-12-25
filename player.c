#include "player.h"

void initPlayer(Player *p) {
  p->num = 0;
  p->name[0] = '\0';
  p->money = 0;
  p->pos.x = p->pos.y = 0;

  initBag(&p->bag);
  // バッグ初期化
}
