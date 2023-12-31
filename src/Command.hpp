#pragma once

#include <string>
#include <vector>

using CmdArgMapping = std::pair<std::string, std::string>;

class Command {
	std::vector<CmdArgMapping> Arguments;

public:
	std::vector<std::string> Name;

	Command();
	void AddArgMapping(std::string arg, std::string mapping);
	void SetName(std::vector<std::string> name);
	std::string MapCmd(std::string mng, std::vector<std::string> args, bool sudo);
};
