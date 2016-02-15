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
}

int sceneProcess(Sugoroku *sugoroku, Scene *scene, SugorokuStatus *sstatus, MyMenu *menus, DispOption *doption, int current_key) {
  switch(*scene) {
  case S_FIELD:
    fieldAction(current_key, sugoroku, sstatus, sstatus->current_player, menus, scene);
    break;
  case S_ITEMMENU:
    break;
  case S_USEITEM:
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
  initCurses();
  initMyMenu(&menus, sugoroku->player_num);
  initSugorokuStatus(&sstatus);
  initMyDispOption(&doption);

  while(!end_flag) {
    current_key = getch();
    if(current_key == 'q') break;
    sceneProcess(sugoroku, &scene, &sstatus, &menus, &doption, current_key);
    //selectAction(current_key, &main_menu);
    //if(current_key == 'a') mvprintw(0, i++, "%d",main_menu.select);
  }
  deleteMyMenu(&menus, sugoroku->player_num);
}
