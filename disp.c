#include "disp.h"
#include <ncurses.h>

void initDispOption(DispOption *doption) {
  doption->std_x = doption->std_y = 0;
  doption->map_w = doption->map_h = 0;
}

int display(Sugoroku *sugoroku, SugorokuStatus *ss, Scene scene, DispOption *doption) {
  Position dpos;
  dpos = sugoroku->player[ss->current_player].pos;
  dpos.x -= doption->map_w/2;
  dpos.y -= doption->map_h/2;
  if(dpos.x < 0) {
    dpos.x = 0;
  } else if(dpos.x >= sugoroku->map.width - doption->map_w) {
    dpos.x = sugoroku->map.width - doption->map_w;
  }
  if(dpos.y < 0) {
    dpos.y = 0;
  } else if(dpos.y >= sugoroku->map.height - doption->map_h) {
    dpos.y = sugoroku->map.height - doption->map_h;
  }
  dispmap(&sugoroku->map, sugoroku->player, sugoroku->player_num, doption->std_x, doption->std_y, dpos, doption->map_w, doption->map_h);

  switch(scene) {
  case S_FIELD:
    break;
  case S_USEITEM:
    break;
  case S_THROWDICE:
    break;
  case S_MOVE:
    break;
  case S_PANELACTION:
    break;
  }
  refresh();
  return 1;
}
