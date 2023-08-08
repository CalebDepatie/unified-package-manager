#pragma once

#include "PackageManager.hpp"

// This will enumerate through all toml files in the given director, returning the managers
std::vector<PackageManager> ReadConfigs(std::string config_dir);