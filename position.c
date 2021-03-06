#include "position.h"
#include <stdlib.h>

void initPosition(Position* p) {
  p->x = p->y = 0;
}

void initPositionList(PositionList* l) {
  l->begin = NULL;
  l->end = NULL;
}

void pushPosition(PositionList* l, Position p) {
  if(l->end == NULL) {
    l->end = (PositionNode*)malloc(sizeof(PositionNode)*1);
    l->end->next = NULL;
    l->end->prev = NULL;
    l->end->pos = p;
    l->begin = l->end;
    return;
  }
  l->end->next = (PositionNode*)malloc(sizeof(PositionNode)*1);
  l->end->next->prev = l->end;
  l->end = l->end->next;
  l->end->next = NULL;
  l->end->pos = p;
}

Position popPosition(PositionList* l) {
  if(l->end == NULL) {
    Position tmp;
    tmp.x = tmp.y = -1;
    return tmp;
  }
  if(l->end == l->begin) {
    Position tmp = l->end->pos;
    free(l->end);
    l->end = l->begin = NULL;
    return tmp;
  }
  l->end = l->end->prev;
  free(l->end->next);
  l->end->next = NULL;
  return l->end->pos;
}

void clearPosition(PositionList* l) {
  PositionNode* ptr = l->begin;
  PositionNode* old = l->begin;
  if(ptr == NULL) return;
  for(; ptr != NULL; old = ptr) {
    ptr = ptr->next;
    free(old);
  }
  l->begin = NULL;
  l->end = NULL;
}

// lの中にpの座標が存在してたら1を返す
int isExistPosition(PositionList* l, Position p) {
  PositionNode* ptr = l->begin;
  for(; ptr != NULL; ptr = ptr->next) {
    if(isPositionEqual(ptr->pos, p)) return 1;
  }
  return 0;
}

int isPositionEqual(Position p1, Position p2) {
  if(p1.x == p2.x && p1.y == p2.y) return 1;
  return 0;
}
