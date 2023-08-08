#include "Command.hpp"

#include <numeric>
#include <iostream>

Command::Command() {}

void Command::AddArgMapping(std::string arg, std::string mapping) {
	this->Arguments.emplace_back(arg, mapping);
}

void Command::SetName(std::vector<std::string> name) {
	this->Name = name;
}

std::string Command::MapCmd(std::vector<std::string> args) {
	
	// Collect cmd args
	std::string cmd = std::accumulate(this->Name.begin(), this->Name.end(), std::string(), 
		[](const std::string& a, const std::string& b) {
		return a + " " + b;
	});

	// Add cmd args
	for (int i = 0; i < args.size(); i++) {
		for (int j = 0; j < this->Arguments.size(); j++) {
			if (args[i] == this->Arguments[j].first) {
				cmd += " " + this->Arguments[j].second;
			}
		}
	}

	return cmd;
}
