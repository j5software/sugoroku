#ifndef __MAP_H__
#define __MAP_H__

typedef struct map{
  int** field;
  int width, height;
} map;

void readMap(map* p, char* dir);
void initMap(map* h, int width, int height);

#endif
