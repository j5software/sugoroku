#include "init.h"
#include "map.h"
#include "bass.h"




int main(void) {
  map m;
  initMap(&m, 8, 8);
  readMap(&m, "./map.dat");
  return 0;
}
