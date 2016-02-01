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
    c = getc(fp);
    while (c != EOF) {
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

// pの座標に移動可能か
int canMove(Map *m, Position p) {
  if(m->field[p.y][p.x] == 0) return 0;
  return 1;
}

// 動かすのに成功したら1、失敗したら0を返す
int movePlayer(Sugoroku* s, int player_id, enum Direction d, PositionList* plist) {
  if(player_id >= s->player_num || player_id < 0) {
    puts("player番号が頭おかしい");
    return 0;
  }
  Position pos = s->player[player_id].pos;
  Position mpos = pos; // 目的の場所
  if(isExistPosition(plist, mpos)) return 0; // 既に行ったことがある場所だったら行かない
  switch(d) {
  case UP:
    mpos.y--;
    if(mpos.y < 0 || !canMove(&s->map, mpos)) return 0;
    break;
  case RIGHT:
    mpos.x++;
    if(mpos.x >= s->map.width || !canMove(&s->map, mpos)) return 0;
    break;
  case DOWN:
    mpos.y++;
    if(mpos.y >= s->map.height || !canMove(&s->map, mpos)) return 0;
    break;
  case LEFT:
    mpos.x--;
    if(mpos.x < 0 || !canMove(&s->map, mpos)) return 0;
    break;
  }
  return 1;
}
