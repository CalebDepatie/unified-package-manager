#pragma once

#include <string>
#include <vector>

// Keeping Macros out of other files for syntactic consistency

// Converting to constexprs as thats my preference
#ifdef DEBUG
	constexpr bool DEBUG_MODE = true;
#else
	constexpr bool DEBUG_MODE = false;
#endif

#ifdef DEBUG 
	const std::string CONFIG_DIR = "./configs/";
#else
	const std::string CONFIG_DIR = std::string(DATA_DIR) + "configs/";
#endif

#define print_debug(text) if constexpr (DEBUG_MODE) { std::cout << "DEBUG: " << text << std::endl; }

std::string join_strings(std::vector<std::string> strings, std::string delimiter);
