#pragma once
#include <string>
#include <iostream>

#ifndef CONSOLE_H
#define CONSOLE_H
class Console
{
public:
	static void PrintMenu();
	static void PrintErrorText(std::string);
	static void PrintTitleText(std::string);
};
#endif
