#include "shop.h"
#include <stdlib.h>
#include <stdio.h>

void initShop(Shop *sh, int shop_size) {
  int i;
  sh->size = shop_size;
  sh->item = (ShopItem *)malloc(sizeof(ShopItem)*shop_size);
  for(i = 0; i < shop_size; i ++) {
    sh->item[i].item_id = 0; // アイテム番号を格納する
    sh->item[i].num = 0; // アイテム個数を格納する
    sh->item[i].price = 0; // アイテム値段を格納する
  }
}

void deleteShop(Shop *sh) {
  if(sh->item)
    free(sh->item);
}

int addShopItem(Shop *sh, int item_id, int price, int num) {
  int i;
  for(i = 0; i < sh->size; i++) {
    if(sh->item[i].item_id == item_id) {
      sh->item[i].item_id = item_id;
      sh->item[i].num++;
      return 1;
    }
  }
  for(i = 0; i < sh->size; i++) {
    if(sh->item[i].num == 0) {
      sh->item[i].item_id = item_id;
      sh->item[i].num++;
      return 1;
    }
  }
  return 0;
}

int popShopItem(Shop *sh, int shop_num) {
  if(sh->item[shop_num].num <= 0) {
    return -1;
  }

  sh->item[shop_num].num--;
  return sh->item[shop_num].item_id;
}

int importShop(Shop *sh, char *dir) {
  FILE *fp;
  int i;
  int c;

  if ((fp = fopen(dir, "r")) == NULL) {
    printf("can't open shop file.\n");
    return 0;
  }

  sh->size = 0;
  do {
    c = getc(fp);
    if (c == '\n') {
      sh->size++;
    }
  } while (c != EOF);

  fclose(fp);
  if ((fp = fopen(dir, "r")) == NULL) {
    printf("can't open shop file.\n");
    return 0;
  }

  sh->item = (ShopItem *)malloc((sizeof(ShopItem)* sh->size));

  for (i = 0; i < sh->size; i++) {
    fscanf(fp, "%d, %d, %d\n", &sh->item[i].item_id, &sh->item[i].price, &sh->item[i].num);
  }

  fclose(fp);
  return 1;
}
