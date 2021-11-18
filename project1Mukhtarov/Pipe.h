#pragma once
class Pipe
{
public:
	void set_id(int);
	int get_id();
	void set_diametr(int);
	int get_diametr();
	void set_length(double);
	double get_length();
	void set_remont(bool);
	bool get_remont();
private:
	int id, diametr;
	double length;
	bool remont;

};

