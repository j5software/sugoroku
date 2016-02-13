#include "sugorokuMain.h"
#include <ncurses.h>
#include "action.h"
#include "disp.h"

void sugorokuMain(Sugoroku* sugoroku) {
  int i= 0;
  int current_key = 0;
  int end_flag = 0;
  Scene scene = S_FIELD;
  SugorokuStatus sstatus;
  DispOption doption;

  if(!initSugoroku(sugoroku, 4)) return;
  initCurses();
  Menu main_menu;
  initMainMenu(&main_menu);

  initSugorokuStatus(&sstatus);
  initDispOption(&doption);
  doption.map_h = doption.map_w = 10; // 表示するマップの範囲は10*10
  while(!end_flag) {
    current_key = getch();
    display(sugoroku, &sstatus, scene, doption);
    //dispmap(&sugoroku->map, sugoroku->player, 1, 3, p, 10, 10);
    if(current_key == 'q') end_flag = 1;
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
