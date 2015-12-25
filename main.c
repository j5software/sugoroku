#include "init.h"
#include "map.h"
#include "bass.h"
#include "action.h"
#include "ncurses.h"

int main(void) {
  Sugoroku sugoroku;

  initCurses();
  sugorokuMain(&sugoroku);

  endwin();
  return 0;
}
