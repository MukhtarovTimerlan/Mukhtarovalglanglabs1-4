#pragma once
#include <string>
#ifndef VERIFICATION_H
#define VERIFICATION_H
namespace Verification
{
	int getint(std::string, std::string, int, int);
	size_t getsize_t(std::string, std::string, size_t, size_t);
	double getdouble(std::string, std::string, double, double);
	bool getbool(std::string, std::string);
	std::string getstring(std::string, std::string, size_t);
	bool checkemptyinput(std::string);
};
#endif
