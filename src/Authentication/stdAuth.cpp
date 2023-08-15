#include "stdAuth.hpp"

#include <unistd.h>
#include <iostream>

bool stdAuth::IsAuthenticated() {
	if (geteuid() == 0)
		return true;

	return false;
}

bool stdAuth::Authenticate() {
	std::cout << "You must be root to use this program reliably." << std::endl;
	std::cout << "Many package managers will require elevated permissions to run." << std::endl;
	exit(0);
}
