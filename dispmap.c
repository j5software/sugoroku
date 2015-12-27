#include "dispmap.h"
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

void dispmap(Map* p)
{
  int i,j;

  for (i = 0; i < p->height; i++) {
    for (j = 0; j < p->width; j++) {
      move(i+1,j);
      printw("%d",p->field[i][j]);
      refresh();
    }
  }
}
