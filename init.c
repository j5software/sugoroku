#include <stdio.h>
#include <locale.h>
#include "init.h"

void initCurses() {
  setlocale(LC_ALL,"");
  initscr();
  curs_set(0);
  noecho();
  cbreak();
  timeout(1);
  keypad(stdscr,TRUE);
  clear();
}

void inputName(Player *p)
{
  //change after
  printf("input player name\n");
  scanf("%s", p->name);
}
