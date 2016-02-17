#ifndef __MAP_H__
#define __MAP_H__

typedef struct Map{
  int** field;
  int width, height;
} Map;

typedef enum MasuNum {
  VOID = 0,
  EMPTY = 1,
  START = 2,
  GOAL = 3,
  SHOP = 4,
  COIN = 5
} MasuNum;

int readMap(Map* p, char* dir);
void initMap(Map* h, int width, int height); // 直接使うことはないかも

#endif
