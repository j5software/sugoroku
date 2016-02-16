#include "sugorokuMain.h"
#include <ncurses.h>
#include "action.h"
#include "init.h"

void initMyDispOption(DispOption *doption) {
  doption->map_w = 15; // 表示するマップの範囲は15*10
  doption->map_h = 8;
  doption->std_x = 5;
  doption->std_y = 3;
  doption->mes_x = doption->std_x + 3;
  doption->mes_y = doption->std_y + doption->map_h*MASU_H + 3;
  doption->menu_x = doption->std_x + doption->map_w*MASU_W + 3;
  doption->menu_y = doption->std_y + 2;
}

int setUseItem(Sugoroku *s) {
  s->item[0].use = useItem0;
  s->item[1].use = useItem1;
  s->item[2].use = useItem2;
  s->item[3].use = useItem3;
  s->item[4].use = useItem4;
  s->item[5].use = useItem5;
  s->item[6].use = useItem6;
  s->item[7].use = useItem7;
  s->item[8].use = useItem8;
  return 1;
}

int sceneProcess(Sugoroku *sugoroku, Scene *scene, SugorokuStatus *sstatus, MyMenu *menus, DispOption *doption, int current_key) {
  switch(*scene) {
  case S_FIELD:
    fieldAction(current_key, sugoroku, sstatus, sstatus->current_player, menus, scene);
    break;
  case S_ITEMMENU:
    itemMenuAction(current_key, sugoroku, sstatus, sstatus->current_player, menus, scene);
    break;
  case S_SELECT_TARGET:
    selectTargetAction(current_key, sugoroku, sstatus, sstatus->current_player, menus, scene);
    break;
  case S_USEITEM:
    useItemAction(current_key, sugoroku, sstatus, sstatus->current_player, scene);
    break;
  case S_THROWDICE:
    throwDiceAction(current_key, sugoroku, sstatus, sstatus->current_player, scene);
    break;
  case S_MOVE:
    moveAction(current_key, sugoroku, sstatus, sstatus->current_player, scene);
    break;
  case S_PANELEVENT:
    panelEventAction(current_key, sugoroku, sstatus, sstatus->current_player, scene);
    break;
  case S_RESULT:
    resultAction(current_key, sugoroku, sstatus, sstatus->current_player, scene);
    break;
  case S_QUIT:
    return 0;
    break;
  }
  display(sugoroku, sstatus, menus, *scene, doption);
  return 1;
}

void sugorokuMain(Sugoroku *sugoroku) {
  int current_key = 0;
  int end_flag = 0;
  Scene scene = S_FIELD;
  SugorokuStatus sstatus;
  DispOption doption;
  MyMenu menus;

  if(!initSugoroku(sugoroku, 1)) return;
  strcpy(sugoroku->player[0].name, "zero");
  sugoroku->player[0].bag.items[0].item_id = 6;
  sugoroku->player[0].bag.items[0].num = 1;
  initCurses();
  initMyMenu(&menus, sugoroku);
  initSugorokuStatus(&sstatus);
  initMyDispOption(&doption);
  setUseItem(sugoroku);
  setItemMenuAll(&menus, sugoroku);

  while(!end_flag) {
    current_key = getch();
    if(current_key == 'q') break;
    end_flag = !sceneProcess(sugoroku, &scene, &sstatus, &menus, &doption, current_key);
  }

  deleteMyMenu(&menus, sugoroku);
  finalizeSugoroku(sugoroku);
  endwin();
}
