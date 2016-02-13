#include "sugorokuMain.h"
#include <ncurses.h>
#include "action.h"
#include "disp.h"
#include "init.h"

int sceneProcess(Sugoroku *sugoroku, Scene *scene, SugorokuStatus *sstatus, DispOption *doption, int current_key) {
  switch(*scene) {
  case S_FIELD:
    break;
  case S_USEITEM:
    break;
  case S_THROWDICE:
    break;
  case S_MOVE:
    moveAction(current_key, sugoroku, sstatus, sstatus->current_player);
    break;
  case S_PANELACTION:
    break;
  case S_RESULT:
    break;
  }
  display(sugoroku, sstatus, *scene, doption);
  return 1;
}

void sugorokuMain(Sugoroku *sugoroku) {
  int current_key = 0;
  int end_flag = 0;
  Scene scene = S_MOVE;
  SugorokuStatus sstatus;
  DispOption doption;
  Menu main_menu;

  if(!initSugoroku(sugoroku, 4)) return;
  initCurses();
  initMainMenu(&main_menu);
  initSugorokuStatus(&sstatus);
  initDispOption(&doption);
  doption.map_w = 15; // 表示するマップの範囲は15*11
  doption.map_h = 11;
  doption.std_x = 5; // 表示するマップの範囲は15*11
  doption.std_y = 3;

  while(!end_flag) {
    current_key = getch();
    if(current_key == 'q') break;
    sceneProcess(sugoroku, &scene, &sstatus, &doption, current_key);
    selectAction(current_key, &main_menu);
    //if(current_key == 'a') mvprintw(0, i++, "%d",main_menu.select);
  }
 /*
  while(!end_flag) {
    current_key = getch();
    render();
    switch(scene) {
    case S_FIELD:
      selectAction();
      break;
    case S_USEITEM:
      useItemAction();
      break;
    case S_THROWDICE:
      dice = throwDice();
      break;
    case S_MOVE:
      getmove(dice);
      end_flag = judgeGoal(); //?
      break;
    case S_PANELACTION
      panelAction();
      break;
    }
  }*/
  deleteMenu(&main_menu);
}
