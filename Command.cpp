#include "Command.hpp"

Command::Command() {}

void Command::AddArgMapping(std::string arg, std::string mapping) {
	this->Arguments.emplace_back(arg, mapping);
}

void Command::SetName(std::vector<std::string> name) {
	this->Name = name;
}