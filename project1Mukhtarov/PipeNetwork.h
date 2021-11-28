#pragma once
#include <unordered_map>
#include"Pipe.h"
#include <vector>
#include <fstream>
#ifndef PIPENETWORK_H
#define PIPENETWORK_H
class PipeNetwork
{
public:
	void AddPipe();
	void changePipe();
	void DeletePipe();
	void BatchChangePipe();
	void SaveToFile(std::ofstream&);
	void DownloadFromFile(std::ifstream&);
	void ShowAllPipes();
	bool emptyPnetwork();


private:
	std::unordered_map<size_t, Pipe> pipeNetwork;
	std::vector<size_t> idfilter;
	void FilterPipe();
	void ShowFilterPipe();
};
#endif
