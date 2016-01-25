#include "init.h"
#include "position.h"
#include <stdio.h>

int main(void) {
  Sugoroku sugoroku;

  initCurses();
  sugorokuMain(&sugoroku);

  endwin();

  return 0;
}
