#pragma once

#include "Command.hpp"
#include <ostream>

class PackageManager {
	std::string Name;
	std::vector<CmdArgMapping> GlobalArgs;
	Command Install;
	Command Remove;
	Command Update;
	Command Search;
	bool Sudo;

public:

	PackageManager(std::string name, bool sudo = false);
	void AddGlobalArgMapping(std::string arg, std::string mapping);
	void SetInstallCommand(Command cmd);
	void SetRemoveCommand(Command cmd);
	void SetUpdateCommand(Command cmd);
	void SetSearchCommand(Command cmd);
	
	std::string GetName() const;

	int ExecuteInstall(std::vector<std::string> packages, std::vector<std::string> args);
	int ExecuteRemove(std::vector<std::string> packages, std::vector<std::string> args);
	int ExecuteUpdate(std::vector<std::string> packages, std::vector<std::string> args);
	int ExecuteSearch(std::string search_term, std::vector<std::string> args);

	friend std::ostream& operator<<(std::ostream& os, const PackageManager& pm) {
		os << "PackageManager(Name=" << pm.Name << ")";
		return os;
	}
};
