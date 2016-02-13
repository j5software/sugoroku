#include "action.h"
#include <ncurses.h>

void selectAction(int current_key, Menu *m) {
  switch(current_key) {
  case KEY_UP:
    moveMenuUp(m);
    break;
  case KEY_DOWN:
    moveMenuDown(m);
    break;
  }
}

void moveAction(int current_key, Sugoroku *s, SugorokuStatus* ss, int player_id) {
  switch(current_key) {
  case KEY_UP:
    movePlayer(s, player_id, UP, &ss->plist);
    break;
  case KEY_RIGHT:
    movePlayer(s, player_id, RIGHT, &ss->plist);
    break;
  case KEY_DOWN:
    movePlayer(s, player_id, DOWN, &ss->plist);
    break;
  case KEY_LEFT:
    movePlayer(s, player_id, LEFT, &ss->plist);
    break;
  }
}
