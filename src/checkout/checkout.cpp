#include <fstream>
#include <string>

int checkout(int argc, char **argv) {
  const std::string HASH = argv[2];
  const std::string filepath = argv[3];

  std::string commitVersionFile = ".dot/commits/" + HASH;
  std::ifstream file(commitVersionFile, std::ios::binary);

  std::string content(std::istreambuf_iterator<char>(file), {});

  std::ofstream target(filepath, std::ios::binary | std::ios::trunc);
  target.write(content.data(), content.size());

  return 0;
}
