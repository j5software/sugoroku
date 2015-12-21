#include "action.h"
#include <ncurses.h>

int current_key = 0;

void readKey() {
  current_key = getch();
}

void selectAction() {
  switch(current_key) {
  case KEY_UP:
    selection = (selection-1)%4; // ←ゴミ
    break;
  case KEY_DOWN:
    selection = (selection+1)%4;
    break;
  }
}
