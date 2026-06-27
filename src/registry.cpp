#include "init/initialize.h"
#include "registry.h"

std::unordered_map<std::string, Command> commands = {{"init", init}};
