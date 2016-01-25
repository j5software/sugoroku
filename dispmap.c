#include "dispmap.h"
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

int dispmap(Map* s, int x, int y, Player* p, int width, int height)
{
  int i,j;
  int k,l;
  int a,b;
  char temp[4][5] ={{"+---+"},
		    {"|   |"},
		    {"|   |"},
		    {"+---+"}}; //表示マステンプレート

  //今のところ考えられるパラメータ異常
  if (width < 0 || width > 5 || height < 0 || height > 5 || p->pos.x < 0 || p->pos.x > 5 || p->pos.y < 0 || p->pos.y > 5) {
    return 0;
  }
  else {
    for (i = 0; i < height; i++) {
      for (j = 0; j < width; j++) {
	temp[1][2] = ' ';
	temp[2][2] = ' ';
	a = p->pos.y + i;
	b = p->pos.x + j;

	/* 表示パターン列挙 */
	if (s->field[a][b] == 2) {
	  temp[1][2] = 'S';
	}
	else if (s->field[a][b] == 3) {
	  temp[1][2] = 'G';
	}
	else if (s->field[a][b] >= 4) {
	  temp[1][2] = '?';
	}
	else if (s->field[a][b] >= 11) {
	  temp[1][2] = (s->field[a][b] % 10)+'0';
	}
	else if (s->field[a][b] >= 21) {
	  temp[1][2] = (s->field[a][b] % 10)+'0';
	}

	/* プレイヤー位置 */
	if (a == p->pos.y && b == p->pos.x) {
	  temp[2][2] = '@';
	}

	/* マス表示 */
	for (k = 0; k < 4; k++) {
	  for (l = 0; l < 5; l++) {
	    if (s->field[a][b] == 0) {
	      mvprintw(x+k+4*i,y+l+5*j," ");
	    }
	    else {
	      mvprintw(x+k+4*i,y+l+5*j,"%c",temp[k][l]);
	    }
	    refresh();
	  }
	}
      }
    }
    return 1;
  }
}
