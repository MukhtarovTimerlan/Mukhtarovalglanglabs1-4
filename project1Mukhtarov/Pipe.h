#pragma once
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
private:
	size_t id;
	static size_t MaxidPipe;
};

#endif 