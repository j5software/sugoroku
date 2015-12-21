#include "map.h"
#include <stdio.h>
#include <stdlib.h>

void initMap(map* h, int width, int height) {
  int i;
  h->field = (int**)malloc(sizeof(int*)*height);
  h->width = width;
  h->height = height;

  for(i = 0; i < width; i++) {
    h->field[i] = (int*)malloc(sizeof(int)*width);
  }
}

void readMap(map* p, char* dir) {
  FILE* fp;
  int ch = 0;
  int x, y;

  fp = fopen(dir, "rb");
  if(fp == NULL) {
    printf("Can't open map file.");
    return;
  }

  for(y = 0; y < p->height; y++) {
    for(x = 0; x < p->width; x++) {
      //ch = getc(fp);
      fscanf(fp, "%d", &ch);
      printf("%3X", ch);
      if(ch == EOF) {
        printf("MapFile format error.");
        return;
      }
      p->field[y][x] = ch;
    }
    puts("");
  }

  fclose(fp);
}
