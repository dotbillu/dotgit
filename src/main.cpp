#include "registry.h"
int main(int argc, char *argv[]) {
  commands[argv[1]](argc, argv);
  return 0;
}
