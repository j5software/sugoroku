#include "sugoroku.h"
#include <stdlib.h>
#include <ncurses.h>
#include "dispmap.h"
#include "scene.h"

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
  int i= 0;
  int current_key = 0;
  enum Scene scene = s_field;
  int end_flag = 0;

  initSugoroku(sugoroku, 4);
  readMap(&sugoroku->map, "./map.dat");
  Menu main_menu;
  initMainMenu(&main_menu);
  mvprintw(10, 10, "%s", main_menu.str[3]);
  while(!end_flag) {
    dispmap(&sugoroku->map, 0, 0, sugoroku->player, 4, 4);
    current_key = getch();
    if(current_key == 'q') end_flag = 1;
    selectAction(current_key, &main_menu);
    //if(current_key == 'a') mvprintw(0, i++, "%d",main_menu.select);
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
  deleteMenu(&main_menu);
}

void initMainMenu(Menu* main_menu) {
  initMenu(main_menu, 4);
  setMenuStr(main_menu, 0, "Throw dice");
  setMenuStr(main_menu, 1, "Item");
  setMenuStr(main_menu, 2, "Save");
  setMenuStr(main_menu, 3, "Quit game");
}

void importItemFile(Sugoroku* sugoroku)
{
  FILE *fp;
  int i;
  int c;

  if ((fp = fopen("item.csv", "r")) != NULL) {
    printf("can't open file.\n");
    exit(1);
  }

  if (fp) {
    sugoroku->item_num = 0;
    while ((c = getc(fp)) != EOF) {
      if (c == '\n') {
        sugoroku->item_num++;
      }
    }

    sugoroku->item = (Item *)malloc((sizeof(Item)* sugoroku->item_num));

    for (i = 0; i < sugoroku->item_num; i++) {
      fscanf(fp, "%d, %s\n", &sugoroku->item[i].id,  sugoroku->item[i].name);
    }

  }

  fclose(fp);
}
