#ifndef __DISPOPTION_H__
#define __DISPOPTION_H__

typedef struct DispOption {
  int std_x, std_y; // 表示の基準の位置
  int map_w, map_h; // 表示するマップの幅と高さ
  int mes_x, mes_y; // メッセージとかの表示位置
  int menu_x, menu_y; // ルートメニューの位置
} DispOption;

#endif
