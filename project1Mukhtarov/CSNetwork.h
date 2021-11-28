#pragma once
#include <unordered_map>
#include "CS.h"
#ifndef CSNETWORK_H
#define CSNETWORK_H
class CSNetwork
{
public:
	void AddCS();
	void ChangeCS();
	void DeleteCS();
	void ShowAllCS();
	bool emptyCnetwork();
private:
	std::unordered_map<size_t, CS> csNetwork;
};
#endif
