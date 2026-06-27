#include "initialize.h"
#include <sys/stat.h>

int init(int argc, char **argv) {
  mkdir("dot", 0755);
  return 0;
}
