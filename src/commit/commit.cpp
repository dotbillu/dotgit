#include <filesystem>
#include <iostream>

int commit(int argc, char **argv) {

  std::filesystem::rename(".dot/staged/*", ".dot/commit/*");

  for (const auto &entry : std::filesystem::directory_iterator(".dot/staged")) {
    std::filesystem::rename(entry.path(),
                            ".dot/commit/" + entry.path().filename().string());
  }
  return 0;
}
