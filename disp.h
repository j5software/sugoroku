#ifndef __DISP_H__
#define __DISP_H__
#include "dispmap.h"
#include "dispmenu.h"
#include "scene.h"
#include "sugoroku.h"

typedef struct DispOption {
  int std_x, std_y; // 表示の基準の位置
  int map_w, map_h; // 表示するマップの幅と高さ
} DispOption;

void initDispOption(DispOption *doption);
int display(Sugoroku *sugoroku, SugorokuStatus *ss, Scene scene, DispOption doption);

#endif
