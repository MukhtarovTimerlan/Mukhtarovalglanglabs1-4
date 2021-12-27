#pragma once
#include <fstream>
#ifndef PIPE_H
#define PIPE_H


class Pipe
{
public:
	Pipe();
	int diametr;
	double length;
	bool remont;
	void ChangePipe();
	friend class PipeNetwork;
	friend class GasTransportSystem;
	Pipe(std::ifstream&);
	void SaveToFile(std::ofstream&);
	size_t idin=0, idout=0;
	static size_t GetMaxId();
private:
	size_t id;
	static size_t MaxidPipe;
};

#endif 