#pragma once
#include <vector>
#include "../PackageManager.hpp"

void* guile_main(void *data);

std::vector<PackageManager> GetPackageManagers();