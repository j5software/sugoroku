#ifndef __POSITION_H__
#define __POSITION_H__

typedef struct Position {
  int x;
  int y;
} Position;

typedef struct PositionNode {
  struct PositionNode* prev;
  struct PositionNode* next;
  Position pos;
} PositionNode;

typedef struct PositionList {
  PositionNode* begin;
  PositionNode* end;
} PositionList;

void initPosition(Position* p);
void initPositionList(PositionList* l);
void pushPosition(PositionList* l, Position p);
void clearPosition(PositionList* l);

#endif
