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
  l->end->pos = p;
}

void clearPosition(PositionList* l) {
  PositionNode* ptr = l->begin;
  PositionNode* old = l->begin;
  if(ptr == NULL) return;
  for(; ptr != NULL; old = ptr) {
    ptr = ptr->next;
    free(old);
  }
}
