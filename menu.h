#ifndef __MENU_H__
#define __MENU_H__

typedef struct Menu {
  char** str; // 2次元配列 表示する文字列
  int menu_num;
} Menu;

void initMenu(Menu* m, int menu_num);
void setMenuStr(Menu* m, int set_num, char* str);
void deleteMenu(Menu* m);

#endif
