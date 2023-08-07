#pragma once

#include <string>
#include <vector>
#include <utility>

using CmdArgMapping = std::pair<std::string, std::string>;

class Command {
	std::string Name;
	std::vector<CmdArgMapping> Arguments;
};

class PackageManager {
	std::vector<CmdArgMapping> GlobalArgs;
	Command Install;
	Command Remove;
	Command Update;
	Command Search;
};