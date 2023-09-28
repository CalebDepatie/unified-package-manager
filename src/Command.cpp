#include "Command.hpp"

#include <numeric>

Command::Command() {}

void Command::AddArgMapping(std::string arg, std::string mapping) {
	this->Arguments.emplace_back(arg, mapping);
}

void Command::SetName(std::vector<std::string> name) {
	this->Name = name;
}

// FIXME: This is hacky and doesn't work as intended
std::string Command::MapCmd(std::string mng, std::vector<std::string> args, bool sudo) {
	
	// Collect cmd args
	std::string cmd = std::accumulate(this->Name.begin(), this->Name.end(), std::string(), 
		[mng, sudo](const std::string& a, const std::string& b) {
		if (a.empty()) {
			auto cmd_str = mng + " " + b;
			if (sudo) {
				cmd_str = "sudo " + cmd_str;
			}

			return cmd_str;
		}

		auto cmd_str = mng + " " + b;
		if (sudo) {
			cmd_str = "sudo " + cmd_str;
		}

		return a + " && " + cmd_str;
	});


	// Add cmd args
	// for (int i = 0; i < args.size(); i++) {
	// 	for (int j = 0; j < this->Arguments.size(); j++) {
	// 		if (args[i] == this->Arguments[j].first) {
	// 			cmd += " " + this->Arguments[j].second;
	// 		}
	// 	}
	// }


	return cmd;
}
