#pragma once

#include "IAuth.hpp"

class stdAuth : public IAuth {
public:
	stdAuth() = default;
	~stdAuth() = default;
	bool Authenticate();
	bool IsAuthenticated();
};
