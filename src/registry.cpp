#include "commit/commit.h"
#include "init/initialize.h"
#include "registry.h"
#include "stage/addition.h"

std::unordered_map<std::string, Command> commands = {
    {"init", init}, {"add", add}, {"commit", commit}};
