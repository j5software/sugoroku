#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "init.h"
#include "map.h"

int throwDice(void)
{
  int num;

  srand((unsigned)time(NULL));
  num = rand() % 6 + 1;

  return num;
}

void movePlayer(player *p, map *m)
{

}

void openBag(void)
{

}

void openMenu(void)
{

}

void selectMenu(void)
{

}

void save(void)
{

}

void load(void)
{

}
