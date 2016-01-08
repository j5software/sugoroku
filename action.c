#include "action.h"
#include "menu.h"
#include <ncurses.h>

void selectAction(int current_key, Menu* m) {
  switch(current_key) {
  case KEY_UP:
    moveMenuUp(m);
    break;
  case KEY_DOWN:
    moveMenuDown(m);
    break;
  }
}


