#include "addition.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <istream>
#include <iterator>
#include <openssl/sha.h>
#include <string>

std::string createHash(const std::string &content);
int add(int argc, char **argv) {

  std::string filepath = argv[2];
  std::ifstream file(filepath, std::ios::binary);

  std::string content(std::istreambuf_iterator<char>(file), {});

  const std::string hashedname = createHash(content);
  const std::string destination = std::string(".dot/staged") + "/" + hashedname;
  std::filesystem::copy_file(filepath, destination);

  return 0;
}

std::string createHash(const std::string &content) {
  unsigned char hash[SHA_DIGEST_LENGTH];

  SHA1(reinterpret_cast<const unsigned char *>(content.data()), content.size(),
       hash);

  std::stringstream ss;

  for (int i = 0; i < SHA_DIGEST_LENGTH; i++) {
    ss << std::hex << std::setw(2) << std::setfill('0')
       << static_cast<int>(hash[i]);
  }

  return ss.str();
}
