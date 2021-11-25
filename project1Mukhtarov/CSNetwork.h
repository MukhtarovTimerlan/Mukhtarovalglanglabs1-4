#pragma once
#include <unordered_map>
#include "CS.h"

class CSNetwork
{
public:
	void AddCS();
	void ChangeCS();
private:
	std::unordered_map<size_t, CS> csNetwork;
};

