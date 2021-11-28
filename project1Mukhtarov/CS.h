#pragma once
#include <string>

#ifndef CS_H
#define CS_H

class CS
{
private:
		size_t id;
		static size_t MaxidCS;
public:
		CS();
		int count_of_CS = -1,
		count_of_CS_in_work = -1,
		effective = -1;
	std::string name_CS;
	void ChangeCS();
	friend class CSNetwork;
};

#endif 
