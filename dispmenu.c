#include "dispmenu.h"
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

int dispmenu(Menu* m, int x, int y)
{
  int x1;
  //m->select=3;
  for(x1=0; x1<m->menu_num+2; x1++){
    if(x1==0 || x1==m->menu_num+1)
      mvprintw(x+x1,y,"==================");
    else {
      mvprintw(x+x1,y,"||              ||");
      mvprintw(x+x1,y+4,"%s",m->str[x1-1]);
    }
  }
    x1=m->select+1;
    //attrset(A_DIM);
    attron(A_BLINK); 
    mvprintw(x+x1,y+3,">");
    attrset(A_NORMAL);

    return 1;
}


//vprintw(y, 0, "A_STANDOUT");
