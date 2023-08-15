#pragma once

class IAuth {
public:
	virtual ~IAuth() = default;
	virtual bool Authenticate() = 0;
	virtual bool IsAuthenticated() = 0;
};
