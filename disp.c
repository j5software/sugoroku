#include "disp.h"
#include <ncurses.h>
#include <stdlib.h>

void initDispOption(DispOption *doption) {
  doption->std_x = doption->std_y = 0;
  doption->map_w = doption->map_h = 0;
  doption->mes_x = doption->mes_y = 0;
}

void dispField(Sugoroku *s, SugorokuStatus *ss, MyMenu *mymenu, DispOption *doption) {
  dispmenu(&mymenu->main_menu, doption->std_x+doption->map_w*MASU_W+3, doption->std_y+2);
  mvprintw(doption->mes_y, doption->mes_x, "[%d] %sの番", ss->current_player, s->player[ss->current_player].name);
}

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
        int plural_flag = 0;
        for (k = 0; k < player_num; k++) {
          if (i == p[k].pos.y && j == p[k].pos.x) {
            plural_flag++;
            temp[2][2] = '0' + k;
          }
        }
        if(plural_flag > 1) {
            temp[2][2] = '@';
        }
      }

      /* マス表示 */
      for (k = 0; k < 4; k++) {
        for (l = 0; l < 5; l++) {
          attrset(0);
          if (i < 0 || i >= m->height || j < 0 || j >= m->width || m->field[i][j] == 0 ) {
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

int dispmenu(Menu* m, int x, int y) {
  int x1;
  //m->select=3;
  for(x1=0; x1<m->menu_num+2; x1++){
    if(x1==0 || x1==m->menu_num+1)
      mvprintw(y+x1,x,"==================");
    else {
      mvprintw(y+x1,x,"||              ||");
      mvprintw(y+x1,x+4,"%s",m->str[x1-1]);
    }
  }
  x1=m->select+1;
  //attrset(A_DIM);
  attron(A_BLINK);
  mvprintw(y+x1,x+3,">");
  attrset(A_NORMAL);

  return 1;
}

void dispThrowDice(SugorokuStatus *ss, DispOption *doption) {
  mvprintw(doption->mes_y, doption->mes_x, "Enterキーでサイコロを振ってね！... %d", rand()%6 + 1);
}

void dispMove(SugorokuStatus *ss, DispOption *doption) {
  mvprintw(doption->mes_y, doption->mes_x, "あと%d マス", ss->move_num);
}

void dispResult(Sugoroku *s, SugorokuStatus *ss, Scene scene, DispOption *doption) {
  int i;
  for(i = 0; i < s->player_num; i++) {
    mvprintw(doption->mes_y + i, doption->mes_x, "[%d位] %d番 %s殿", s->player[i].ranking, i, s->player[i].name);
  }
}

int display(Sugoroku *sugoroku, SugorokuStatus *ss, MyMenu *mymenu, Scene scene, DispOption *doption) {
  erase();
  Position dpos;
  dpos = sugoroku->player[ss->current_player].pos;
  dpos.x -= doption->map_w/2;
  dpos.y -= doption->map_h/2;
  if(dpos.x < 0) {
    dpos.x = 0;
  } else if(dpos.x >= sugoroku->map.width - doption->map_w) {
    dpos.x = sugoroku->map.width - doption->map_w;
  }
  if(dpos.y < 0) {
    dpos.y = 0;
  } else if(dpos.y >= sugoroku->map.height - doption->map_h) {
    dpos.y = sugoroku->map.height - doption->map_h;
  }
  dispmap(&sugoroku->map, sugoroku->player, sugoroku->player_num, doption->std_x, doption->std_y, dpos, doption->map_w, doption->map_h);

  switch(scene) {
  case S_FIELD:
    dispField(sugoroku, ss, mymenu, doption);
    break;
  case S_ITEMMENU:
  case S_USEITEM:
    break;
  case S_THROWDICE:
    dispThrowDice(ss, doption);
    break;
  case S_MOVE:
    dispMove(ss, doption);
    break;
  case S_PANELEVENT:
    break;
  case S_RESULT:
    dispResult(sugoroku, ss, scene, doption);
    break;
  }
  refresh();
  return 1;
}
