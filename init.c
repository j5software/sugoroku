#include <stdio.h>

#include "init.h"

void initPlayer(player *p)
{
  int i;

  //p->num = 0; 後で改変
  inputName(p);
  p->money = 1000;
  for (i = 0; i < 20; i ++) {
    p->_bag.items[i][0] = -1;      //-1で何も持ってない　アイテム番号を格納する
    p->_bag.items[i][1] = -1;      //-1で何も持ってない　アイテム個数を格納する
  }
  p->pos.x = 0;
  p->pos.y = 0;
}

void initItem(item *p)
{
  //make item  file -> read item file
}

void inputName(player *p)
{
  //change after
  printf("input player name\n");
  scanf("%s", p->name);
}
