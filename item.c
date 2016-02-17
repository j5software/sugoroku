#include "item.h"
#include <ncurses.h>
#include <stdlib.h>

void initItem(Item *i) {
  i->name[0] = '\0';
  i->id = 0;
  i->use = dummy_use;
  i->hastarget = 0;
}

void dummy_use(struct Sugoroku *s, struct SugorokuStatus *ss, int player_id, int target, Scene *scene) {
}
