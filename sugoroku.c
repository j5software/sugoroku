#include "sugoroku.h"
#include <stdlib.h>
#include <stdio.h>

int initSugoroku(Sugoroku* s, int player_num) {
  int i;
  s->player_num = player_num;
  s->player = (Player *)malloc(sizeof(Player)*player_num);
  for(i = 0; i < player_num; i++) {
    initPlayer(&(s->player[i]), i);
  }
  if(!readMap(&s->map, "./map.dat")) return 0;
  if(!importItemFile(s, "./ITEM.csv")) return 0;
  if(!setPlayerStart(s)) return 0;

  return 1;
}

void initSugorokuStatus(SugorokuStatus *ss) {
  ss->current_player = 0;
  ss->move_num = 0;
  initPositionList(&ss->plist);
}

void initMainMenu(Menu* main_menu) {
  initMenu(main_menu, 4);
  setMenuStr(main_menu, 0, "Throw dice");
  setMenuStr(main_menu, 1, "Item");
  setMenuStr(main_menu, 2, "Save");
  setMenuStr(main_menu, 3, "Quit game");
}

int importItemFile(Sugoroku* sugoroku, char* dir)
{
  FILE *fp;
  int i;
  int c;

  if ((fp = fopen(dir, "r")) == NULL) {
    printf("can't open item file.\n");
    return 0;
  }

  sugoroku->item_num = 0;
  do {
    c = getc(fp);
    if (c == '\n') {
      sugoroku->item_num++;
    }
  } while (c != EOF);

  sugoroku->item = (Item *)malloc((sizeof(Item)* sugoroku->item_num));

  for (i = 0; i < sugoroku->item_num; i++) {
    fscanf(fp, "%d, %s\n", &sugoroku->item[i].id,  sugoroku->item[i].name);
  }


  fclose(fp);
  return 1;
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

  // 既に行ったことがある場所だったら行かない
  // 一個前のとこに戻ることは出来る
  if(isExistPosition(plist, mpos)) {
    if(isPositionEqual(plist->end->pos, mpos)) {
      // 進める数を一つ戻す
      s->player[player_id].pos = mpos;
      popPosition(plist);
    } else {
      return 0;
    }
  } else {
    s->player[player_id].pos = mpos;
    pushPosition(plist, pos);
  }
  return 1;
}

// 全てのプレイヤーをスタートの位置に移動
int setPlayerStart(Sugoroku* s) {
  int i, j, k;

  for(i = 0; i < s->map.height; i++) {
    for(j = 0; j < s->map.width; j++) {
      if(s->map.field[i][j] == START) {
        for(k = 0; k < s->player_num; k++) {
          s->player[k].pos.x = j;
          s->player[k].pos.y = i;
          return 1;
        }
      }
    }
  }

  // スタートが無かったとき
  return 0;
}
