#pragma once
#include <unordered_map>
#include"Pipe.h"

class PipeNetwork
{
public:
	void AddPipe();
	void changePipe();

private:
	std::unordered_map<size_t, Pipe> pipeNetwork;
};

