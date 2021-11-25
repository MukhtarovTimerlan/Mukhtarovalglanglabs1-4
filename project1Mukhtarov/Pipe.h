#pragma once
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

