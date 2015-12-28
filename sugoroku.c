#include "sugoroku.h"
#include "dispmap.h"
#include <stdlib.h>
#include <ncurses.h>

void initSugoroku(Sugoroku* s, int player_num) {
  int i;
  s->player_num = player_num;
  s->player = (Player *)malloc(sizeof(Player)*player_num);
  for(i = 0; i < player_num; i++) {
    initPlayer(&(s->player[i]), i);
  }
  // ここにmapの初期化を入れる？
  // ここにitemの初期化を入れる？
}

void sugorokuMain(Sugoroku* sugoroku) {
  int scene = 0;
  int end_flag = 1;
  initSugoroku(sugoroku, 4);
  readMap(&sugoroku->map, "./map.dat");
  while(1) {
    readKey();
    dispmap(&sugoroku->map);
    if(current_key == 'q') break;
    //mvprintw(0, 0, "あ");
  }
 /* 
  while(end_flag) {
    readkey();
    render();
    switch(scene) {
    case 0:
      selectAction();
      break;
    case 1:
      useItemAction();
      break;
    case 2:
      throwDice();
      break;
    case 3:
      getmove();
      break;
    case 4:
      panelAction();
      break;
    case 5:
      end_flag = judgeGoal();
      break;
    }
  }*/
}
