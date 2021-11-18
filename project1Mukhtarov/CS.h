#pragma once
#include <string>;
class CS
{
public:
	void set_id(int);
	int get_id();
	void set_count_of_CS(int);
	int get_count_of_CS();
	void set_count_of_CS_in_work(int);
	int get_count_of_CS_in_work();
	void set_name_CS(std::string);
	std::string get_name_CS();		
private:
	int id = -1,
		count_of_CS = -1,
		count_of_CS_in_work = -1,
		effective = -1;
	std::string name_CS;
};

