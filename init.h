#ifndef __INIT_H__
#define __INIT_H__

typedef struct position
{
  int x;
  int y;
} position;

typedef struct map
{
  int **field;
  int width;
  int height;
} map;

typedef struct bag
{
  int items[20];
} bag;

typedef struct item
{
  char name[20];
} item;

typedef struct player
{
  int num;
  char name[20];
  int money;
  bag items;
  position pos;
} player;



void initPlayer(player *p);
void initMap(map *p);
void initItem(item *p);
void inputName(player *p);

#endif
