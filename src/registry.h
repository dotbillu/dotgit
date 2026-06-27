#pragma once
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

using Command = int(*)(int, char**);
extern std::unordered_map<std::string, Command> commands;
