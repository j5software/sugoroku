#include "init.h"
#include "map.h"
#include "bass.h"
#include "action.h"
#include "ncurses.h"

int main(void) {
  int scene = 0;
  int end_flag = 1;
  map m;

  initCurses();
  initMap(&m, 5, 5);
  readMap(&m, "./map.dat");
  refresh();


  while(1) {
    readKey();
    printw("%d", current_key);
  }
 /* 
  while(end_flag) {
    readkey();
    render();
    switch(scene) {
    case 0:
      selectAction();
      break;
    case 1:
      useItemAction();
      break;
    case 2:
      throwDice();
      break;
    case 3:
      getmove();
      break;
    case 4:
      panelAction();
      break;
    case 5:
      end_flag = judgeGoal();
      break;
    }
  }*/

  endwin();
  return 0;
}
