#pragma once
#include <unordered_map>
#include <vector>
#include "CS.h"
#include <set>
#include <fstream>
#ifndef CSNETWORK_H
#define CSNETWORK_H
class CSNetwork
{
public:
	void AddCS();
	void ChangeCS();
	void DeleteCS();
	void BatchChangeCS();
	void SaveToFile(std::ofstream& fout);
	void DownloadFromFile(std::ifstream& fin);
	void ShowAllCS();
	bool emptyCnetwork();
	friend class GasTransportSystem;
private:
	std::unordered_map<size_t, CS> csNetwork;
	std::vector<size_t> idfilter;
	void FilterCS();
	void PrintFilterCS();
	void ShowFilterCS();
};
#endif
