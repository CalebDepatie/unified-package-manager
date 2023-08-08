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

public:

	PackageManager(std::string name);
	void AddGlobalArgMapping(std::string arg, std::string mapping);
	void SetInstallCommand(Command cmd);
	void SetRemoveCommand(Command cmd);
	void SetUpdateCommand(Command cmd);
	void SetSearchCommand(Command cmd);
	
	std::string GetName() const;

	std::string ExecuteInstall(std::vector<std::string> args);
	std::string ExecuteRemove(std::vector<std::string> args);
	std::string ExecuteUpdate(std::vector<std::string> args);
	std::string ExecuteSearch(std::string search_term, std::vector<std::string> args);

	friend std::ostream& operator<<(std::ostream& os, const PackageManager& pm) {
		os << "PackageManager(Name=" << pm.Name << ")";
		return os;
	}
};
