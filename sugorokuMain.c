#include "sugorokuMain.h"
#include <ncurses.h>
#include "action.h"
#include "dispmap.h"

void sugorokuMain(Sugoroku* sugoroku) {
  int i= 0;
  int current_key = 0;
  enum Scene scene = S_FIELD;
  int end_flag = 0;

  initSugoroku(sugoroku, 4);
  readMap(&sugoroku->map, "./map.dat");
  Menu main_menu;
  initMainMenu(&main_menu);
  mvprintw(10, 10, "%s", main_menu.str[3]);
  Position p;
  p.x = 1, p.y = 0;
  while(!end_flag) {
    dispmap(&sugoroku->map, sugoroku->player, 1, 3, p, 10, 10);
    current_key = getch();
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
