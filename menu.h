#ifndef __MENU_H__
#define __MENU_H__
#include "player.h"

typedef struct Menu {
  char** str; // 2次元配列 表示する文字列
  int menu_num; // メニューの数
  int select; // 選択している場所
} Menu;

// 実際に使うのはこっちか
typedef struct MyMenu {
  Menu main_menu;
  Menu target_menu; // アイテムを使うターゲット
  Menu *item_menu; // 配列[プレイヤー人数]
} MyMenu;

enum MainMenu {
  MM_THROWDICE,
  MM_ITEM,
  MM_SAVE,
  MM_QUIT
};

void initMenu(Menu *m, int menu_num);
void initMainMenu(Menu *main_menu);
void initMyMenu(MyMenu *m, Player players[], int player_num);
void deleteMyMenu(MyMenu *m, int player_num);
void setMenuStr(Menu *m, int set_num, char* str);
void deleteMenu(Menu *m);
void moveMenuUp(Menu *m);
void moveMenuDown(Menu *m);

#endif
