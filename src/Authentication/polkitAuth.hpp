#pragma once

#include "IAuth.hpp"

class polkitAuth : public IAuth {
public:
	polkitAuth() = default;
	~polkitAuth() = default;
	bool Authenticate();
	bool IsAuthenticated();
};
