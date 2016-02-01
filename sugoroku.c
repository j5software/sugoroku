#include "sugoroku.h"
#include <stdlib.h>
#include <stdio.h>

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
