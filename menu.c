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

  m->select = 0;
}

void initMainMenu(Menu *main_menu) {
  initMenu(main_menu, 4);
  setMenuStr(main_menu, MM_THROWDICE, "Throw dice");
  setMenuStr(main_menu, MM_ITEM, "Item");
  setMenuStr(main_menu, MM_SAVE, "Save");
  setMenuStr(main_menu, MM_QUIT, "Quit game");
}


void initMyMenu(MyMenu *m, int player_num) {
  initMainMenu(&m->main_menu);
  m->item_menu = (Menu *)malloc(sizeof(Menu)*player_num);
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

void deleteMyMenu(MyMenu *m, int player_num) {
  int i;

  deleteMenu(&m->main_menu);
  for(i = 0; i < player_num; i++) {
    deleteMenu(&m->item_menu[i]);
  }
  free(m->item_menu);
}

void moveMenuUp(Menu* m) {
  m->select = m->select-1;
  if(m->select < 0) {
    m->select += m->menu_num;
  }
  m->select = m->select%4;
}

void moveMenuDown(Menu* m) {
  m->select = (m->select+1)%4;
}


