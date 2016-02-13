#include "disp.h"

void initDispOption(DispOption *doption) {
  doption->std_x = doption->std_y = 0;
  doption->map_w = doption->map_h = 0;
}

int display(Sugoroku *sugoroku, SugorokuStatus *ss, Scene scene, DispOption doption) {
  Position dpos = sugoroku->player[ss->current_player].pos;
  switch(scene) {
  case S_FIELD:
    dispmap(&sugoroku->map, sugoroku->player, doption.std_x, doption.std_y, dpos, doption.map_w, doption.map_h);
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
  return 1;
}
