#include <filesystem>
#include <iostream>

int log(int argc, char **argv) {

  for (auto &commits : std::filesystem::directory_iterator(".dot/commits")) {
    std::cout << commits.path().filename().string() << std::endl;
  }
  return 0;
}
