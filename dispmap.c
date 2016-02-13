#include "dispmap.h"
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

int dispmap(Map* m, Player* p, int player_num, int x, int y, Position pos, int width, int height)
{
  int i,j;
  int k,l;
  char temp[4][5] ={{"+---+"},
                    {"|   |"},
                    {"|   |"},
                    {"+---+"}}; //表示マステンプレート

  start_color();
  use_default_colors();
  //bkgd();
  init_pair(1, COLOR_RED, -1);
  //mvprintw(20,20,"%d",use_default_colors());
  //今のところ考えられるパラメータ異常
  /*if (width < 0 || width > m->width || height < 0 || height > m->height || pos.x < 0 || pos.x > m->width || pos.y < 0 || pos.y > m->height || pos.x+width > m->width || pos.y+height > m->height) {
    return 0;
  }*/
  //mvprintw(0,0,"p(%d,%d) width:%d height:%d",pos.x, pos.y, width, height);

  for (i = 0; i < m->height; i++) {
    for (j = 0; j < m->width; j++) {
      //mvprintw(i+1,3*j+1,"%d",m->field[i][j]);
    }
  }

  for (i = pos.y; i < pos.y+height; i++) {
    for (j = pos.x; j < pos.x+width; j++) {
      //attrset(COLOR_PAIR(1));
      //mvprintw(i+1,3*j+1,"%d",m->field[i][j]);
    }
  }

  for (i = pos.y; i < pos.y+height; i++) {
    for (j = pos.x; j < pos.x+width; j++) {
      if(i >= 0 && i < m->height && j >= 0 && j < m->width) {
        temp[1][1] = ' ';
        temp[1][2] = ' ';
        temp[1][3] = ' ';
        temp[2][2] = ' ';

        /* 表示パターン列挙 */
        if (m->field[i][j] == 2) {
          temp[1][2] = 'S';
        }
        else if (m->field[i][j] == 3) {
          temp[1][2] = 'G';
        }
        else if (m->field[i][j] >= 21) {
          temp[1][1] = '-';
          temp[1][2] = (m->field[i][j] % 10)+'0';
        }
        else if (m->field[i][j] >= 11) {
          temp[1][1] = '+';
          temp[1][2] = (m->field[i][j] % 10)+'0';
        }
        else if (m->field[i][j] >= 4) {
          temp[1][2] = '?';
        }



        /* プレイヤー位置 */
        for (k = 0; k < player_num; k++) {
          if (i == p[k].pos.y && j == p[k].pos.x) {
            temp[2][2] = '@';
          }
        }
      }

      /* マス表示 */
      for (k = 0; k < 4; k++) {
        for (l = 0; l < 5; l++) {
          attrset(0);
          if (m->field[i][j] == 0 || i < 0 || i >= m->height || j < 0 || j >= m->width) {
            mvprintw(y+k+4*(i-pos.y),x+l+5*(j-pos.x)," ");
          }
          else {
            mvprintw(y+k+4*(i-pos.y),x+l+5*(j-pos.x),"%c",temp[k][l]);
          }
        }
      }
    }
  }
  return 1;
}
