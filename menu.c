#include "menu.h"
#include <stdlib.h>
#include <string.h>

void initMenu(Menu *m, int menu_num) {
  int i;

  m->menu_num = menu_num;
  if(menu_num < 0) menu_num = 1;
  m->str = (char**)malloc(sizeof(char*)*menu_num);
  for(i = 0; i < menu_num; i++) {
    m->str[i] = (char*)calloc(sizeof(char), 20);
  }
}

void setMenuStr(Menu* m, int set_num, char* str) {
  if(set_num >= m->menu_num) return;
  strcpy(m->str[set_num], str);
}

void deleteMenu(Menu* m) {
  int i;
  for(i = 0; i < m->menu_num; i++) {
    free(m->str[i]);
  }
  free(m->str);
}
