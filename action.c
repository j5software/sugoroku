#include "action.h"
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

// nマス戻る
void backPlayer(Sugoroku *s, SugorokuStatus* ss, int player_id, int backnum) {
  int i;
  Position tmp;
  tmp.x = tmp.y = -1;
  for(i = 0; i < backnum-1; i++) {
    s->player[player_id].pos = popPosition(&s->player[player_id].footmark);
    if(isPositionEqual(s->player[player_id].pos, tmp)) {
      return;
    }
  }
}

void panelEventAction(int current_key, Sugoroku *s, SugorokuStatus* ss, int player_id, Scene *scene) {
  Position ppos = s->player[player_id].pos;
  switch(s->map.field[ppos.y][ppos.x]) {
  case GOAL:
    s->player[player_id].is_goal = true;
    ss->goal_player_num++;
    if(ss->goal_player_num >= s->player_num) {
      *scene = S_RESULT;
    }
    clearPosition(&ss->plist);
    break;
  default:
    // nマス進む
    if(s->map.field[ppos.y][ppos.x] >= 11 && s->map.field[ppos.y][ppos.x] < 20) {
      *scene = S_MOVE;
      ss->move_num = s->map.field[ppos.y][ppos.x]%10;
      clearPosition(&ss->plist);
    }
    // nマス戻る
    else if(s->map.field[ppos.y][ppos.x] >= 21 && s->map.field[ppos.y][ppos.x] < 30) {
      backPlayer(s, ss, player_id, s->map.field[ppos.y][ppos.x]%10);
      *scene = S_PANELEVENT;
      clearPosition(&ss->plist);
    }
    // それ以外
    else {
      if(setNextPlayer(s, ss)) {
        *scene = S_FIELD;
      }
      clearPosition(&ss->plist);
    }
    break;
  }
}

void fieldAction(int current_key, Sugoroku *s, SugorokuStatus* ss, int player_id, MyMenu *menus, Scene *scene) {
  if(current_key == '\n') {
    switch(menus->main_menu.select) {
    case MM_THROWDICE:
      *scene = S_THROWDICE;
      break;
    case MM_ITEM:
      break;
    case MM_SAVE:
      break;
    case MM_QUIT:
      break;
    }
  } else {
    selectAction(current_key, &menus->main_menu);
  }
}

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

int throwDice(double rate) {
  int num;

  srand((unsigned)time(NULL));
  num = rand() % 6 + 1;

  return (double)num * rate;
}

void throwDiceAction(int current_key, Sugoroku *s, SugorokuStatus* ss, int player_id, Scene *scene) {
  if(current_key == '\n'){
    ss->move_num = throwDice(ss->dice_rate);
    *scene = S_MOVE;
  }
}

void moveAction(int current_key, Sugoroku *s, SugorokuStatus* ss, int player_id, Scene *scene) {
  switch(current_key) {
  case KEY_UP:
    movePlayer(s, player_id, UP, &ss->plist, ss);
    break;
  case KEY_RIGHT:
    movePlayer(s, player_id, RIGHT, &ss->plist, ss);
    break;
  case KEY_DOWN:
    movePlayer(s, player_id, DOWN, &ss->plist, ss);
    break;
  case KEY_LEFT:
    movePlayer(s, player_id, LEFT, &ss->plist, ss);
    break;
  }
  if(ss->move_num <= 0) *scene = S_PANELEVENT;
  Position pos = s->player[player_id].pos;
  if(s->map.field[pos.y][pos.x] == GOAL) {
    clearPosition(&ss->plist);
  }
}
