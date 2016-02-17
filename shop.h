#ifndef __SHOP_H__
#define __SHOP_H__
#include "item.h"

typedef struct ShopItem {
  int item_id;
  int price;
  int num; // 個数
} ShopItem;

typedef struct Shop {
  // 1アイテム番号,2は個数
  ShopItem *item;
  int size;
} Shop;

void initShop(Shop *sh, int shop_size);
void deleteShop(Shop *sh);
int addShopItem(Shop *sh, int item_id, int price, int num);
int popShopItem(Shop *sh, int shop_num);
int importShop(Shop *sh, char *dir);

#endif
