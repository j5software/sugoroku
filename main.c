#include "init.h"

int main(void) {
  Sugoroku sugoroku;

  initCurses();
  sugorokuMain(&sugoroku);

  endwin();
  return 0;
}
