#pragma once
#include <string>
#include <fstream>

#ifndef CS_H
#define CS_H

class CS
{
private:
		size_t id;
		static size_t MaxidCS;
public:
		CS();
		int count_of_CS,
		count_of_CS_in_work,
		effective;
		CS(std::ifstream&);
		size_t stepenishoda=0, stepenzahoda=0;
		static size_t GetMaxId();
		std::string name_CS;
		void ChangeCS();
		void SaveToFile(std::ofstream&);
		friend class CSNetwork;
		friend class GasTransportSystem;
};

#endif 
