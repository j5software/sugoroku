#include "map.h"

int main(void) {
  map m;
  initMap(&m, 8, 8);
  readMap(&m, "./map.dat");
  return 0;
}
