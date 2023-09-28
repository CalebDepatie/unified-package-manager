#include "PackageManager.hpp"

#include <cstdlib>
#include <iostream>

#include "common.hpp"

PackageManager::PackageManager(std::string name) : Name(name) {}

void PackageManager::AddGlobalArgMapping(std::string arg, std::string mapping) {
	this->GlobalArgs.emplace_back(arg, mapping);
}

void PackageManager::SetInstallCommand(Command cmd) {
	this->Install = cmd;
}

void PackageManager::SetRemoveCommand(Command cmd) {
	this->Remove = cmd;
}

void PackageManager::SetUpdateCommand(Command cmd) {
	this->Update = cmd;
}

void PackageManager::SetSearchCommand(Command cmd) {
	this->Search = cmd;
}

std::string PackageManager::GetName() const { 
	return this->Name; 
}

int PackageManager::ExecuteInstall(std::vector<std::string> packages, std::vector<std::string> args) {
	auto cmd = this->Install.MapCmd(this->Name, args);

	std::cout << " -- " << this->Name << " -- " << std::endl;

	print_debug("Packages: " << join_strings(packages, " ") << " | Command: " << cmd);

	return std::system((cmd + " " + join_strings(packages, " ")).c_str());
}

int PackageManager::ExecuteRemove(std::vector<std::string> packages, std::vector<std::string> args) {
	auto cmd = this->Remove.MapCmd(this->Name, args);

	std::cout << " -- " << this->Name << " -- " << std::endl;

	print_debug("Packages: " << join_strings(packages, " ") << " | Command: " << cmd);

	return std::system((cmd + " " + join_strings(packages, " ")).c_str());
}

int PackageManager::ExecuteUpdate(std::vector<std::string> packages, std::vector<std::string> args) {
	auto cmd = this->Update.MapCmd(this->Name, args);

	std::cout << " -- " << this->Name << " -- " << std::endl;

	print_debug("Packages: " << join_strings(packages, " ") << " | Command: " << cmd);

	if (packages.size() == 0)
		return std::system((cmd).c_str());
	
	else
		return std::system((cmd + " " + join_strings(packages, " ")).c_str());
}

int PackageManager::ExecuteSearch(std::string search_term, std::vector<std::string> args) {
	auto cmd = this->Search.MapCmd(this->Name, args);

	std::cout << " -- " << this->Name << " -- " << std::endl;

	print_debug("Search term: " << search_term << " | Command: " << cmd);
	
	return std::system((cmd + " " + search_term).c_str());;
}
