#ifndef __MAP_H__
#define __MAP_H__

typedef struct Map{
  int** field;
  int width, height;
} Map;

int readMap(Map* p, char* dir);
void initMap(Map* h, int width, int height); // 直接使うことはないかも

#endif
