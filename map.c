#include "Map.h"
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

void initMap(Map* h, int width, int height) {
  int i;
  h->field = (int**)malloc(sizeof(int*)*height);
  h->width = width;
  h->height = height;

  for(i = 0; i < width; i++) {
    h->field[i] = (int*)malloc(sizeof(int)*width);
  }
}

void readMap(Map* p, char* dir) {
  FILE* fp;
  int ch = 0;
  int x, y;

  fp = fopen(dir, "rb");
  if(fp == NULL) {
    printf("Can't open Map file.");
    return;
  }
  fscanf(fp, "%d", &p->width);
  fscanf(fp, "%d", &p->height);
  initMap(p, p->width, p->height);

  for(y = 0; y < p->height; y++) {
    for(x = 0; x < p->width; x++) {
      fscanf(fp, "%d", &ch);
      p->field[y][x] = ch;
    }
  }

  fclose(fp);
}
