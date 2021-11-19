#include "pch.h"
#include "Verification.h"
#include <iostream>
#include "Console.h"
using std::cout;
using std::endl;
using std::cin;

void Verification::validateint(std::string textRequest, std::string textError, int min, int max)// как вернуть значение 
{
    int value;
	cout << textRequest << endl;
    cin >> value;
    while (true) {
        if (!cin || cin.peek() != '\n' || value < min || value > max)
        {
            Console::PrintErrorText(textError);
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> value;
        }
        else
        {
            break;
        }
    }

}

void Verification::validatedouble(std::string textRequest, std::string textError, double min, double max)
{
    double value;
    cout << textRequest << endl;
    cin >> value;
    while (true) {
        if (!cin || cin.peek() != '\n' || value < min || value > max)
        {
            Console::PrintErrorText(textError);
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> value;
        }
        else
        {
            break;
        }
    }

}
