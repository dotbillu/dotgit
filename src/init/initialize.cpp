#include "initialize.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <sys/stat.h>
#include <vector>

const std::string CWD = std::filesystem::current_path().string();
int initialize();

int init(int argc, char **argv) {
  bool reinit = false;
  for (const auto &entry : std::filesystem::directory_iterator(".")) {
    const std::string file = entry.path().filename().string();
    if (file == ".dot") {
      reinit = true;
      break;
    }
  }

  std::cout << (reinit ? "Reinitialized empty Dot repository in "
                       : "Initialized empty Dot repository in ")
            << CWD << std::endl;
  initialize();

  return 0;
}

int initialize() {
  const std::vector<std::string> dirToCreate{".dot", ".dot/staged",
                                             ".dot/commits"};
  const std::vector<std::string> filesToCreate{".dot/description"};

  for (std::string s : dirToCreate) {
    std::filesystem::create_directory(s);
  }

  for (std::string s : filesToCreate) {
    std::filesystem::path file = s;
    std::ofstream ofs(file);
  }

  return 0;
}
