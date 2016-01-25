#include "player.h"

void initPlayer(Player *p, int player_num) {
  p->player_num = player_num;
  p->name[0] = '\0';
  p->money = 0;
  p->pos.x = p->pos.y = 0;

  initBag(&p->bag);
  // バッグ初期化
}
