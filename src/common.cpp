#include "common.hpp"

std::string join_strings(std::vector<std::string> strings, std::string delimiter) {
	std::string result = "";

	for (auto it = strings.begin(); it != strings.end(); ++it) {
		result += *it;

		if (it != strings.end() - 1)
			result += delimiter;
	}

	return result;
}
