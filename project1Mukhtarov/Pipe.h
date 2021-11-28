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
	Pipe(std::ifstream&);
	void SaveToFile(std::ofstream&);
private:
	size_t id;
	static size_t MaxidPipe;
};

#endif 