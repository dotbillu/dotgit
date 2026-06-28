#include <filesystem>
#include <iostream>

int commit(int argc, char **argv) {
  for (const auto &entry : std::filesystem::directory_iterator(".dot/staged")) {
    std::filesystem::rename(entry.path(),
                            ".dot/commits/" + entry.path().filename().string());
  }
  return 0;
}
