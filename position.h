#ifndef __POSITION_H__
#define __POSITION_H__

enum Direction {
  UP,RIGHT,DOWN,LEFT
};

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
void popPosition(PositionList* l);
void clearPosition(PositionList* l);
int isExistPosition(PositionList* l, Position p);
int isPositionEqual(Position p1, Position p2);

#endif
