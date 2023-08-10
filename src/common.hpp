#pragma once

#include <string>
#include <vector>

// converting to constexprs as thats my preference
#ifdef DEBUG
	constexpr bool DEBUG_MODE = true;
#else
	constexpr bool DEBUG_MODE = false;
#endif

std::string join_strings(std::vector<std::string> strings, std::string delimiter);
