#include "init.h"
#include "sugorokuMain.h"
#include <stdio.h>

int main(void) {
  Sugoroku sugoroku;

  initCurses();
  sugorokuMain(&sugoroku);

  endwin();

  return 0;
}
