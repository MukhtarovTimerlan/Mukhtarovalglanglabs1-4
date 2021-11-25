#pragma once
#include <string>
namespace Verification
{
	static int getint(std::string, std::string, int, int);
	size_t getsize_t(std::string, std::string, size_t, size_t);
	static double getdouble(std::string, std::string, double, double);
	static bool getbool(std::string, std::string);
	std::string getstring(std::string, std::string, size_t);
	bool checkemptyinput(std::string);
};

