#include "PackageManager.hpp"

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