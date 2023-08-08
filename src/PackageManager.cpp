#include "PackageManager.hpp"

#include <cstdlib>
#include <iostream>

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

std::string PackageManager::ExecuteInstall(std::vector<std::string> args) {
	auto cmd = this->Install.MapCmd(args);
	
	return this->Name + cmd;
}

std::string PackageManager::ExecuteRemove(std::vector<std::string> args) {
	auto cmd = this->Remove.MapCmd(args);
	
	return this->Name + cmd;
}

std::string PackageManager::ExecuteUpdate(std::vector<std::string> args) {
	auto cmd = this->Update.MapCmd(args);
	
	return this->Name + cmd;
}

std::string PackageManager::ExecuteSearch(std::string search_term, std::vector<std::string> args) {
	auto cmd = this->Search.MapCmd(args);

	std::cout << " -- " << this->Name << " -- " << std::endl;

	std::system((this->Name + cmd + " " + search_term).c_str());
	
	return "";
}
