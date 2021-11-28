#include "pch.h"
#include "Verification.h"
#include <iostream>
#include "Console.h"
#include <set>
using std::cout;
using std::endl;
using std::cin;

bool Verification::checkemptyinput(std::string str)
{
    int i = 0;
    while (i != size(str))
    {
        if (str[i] != ' ')
            return true;
        ++i;
    }
    return false;
}

int Verification::getint(std::string textRequest, std::string textError, int min, int max)
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
    return(value);
}
size_t Verification::getsize_t(std::string textRequest, std::string textError, size_t min, size_t max)
{
    size_t value;
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
    return(value);
}

double Verification::getdouble(std::string textRequest, std::string textError, double min, double max)
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
    return(value);
}

bool Verification::getbool(std::string textRequest, std::string textError)
{
    bool value;
    cout << textRequest << endl;
    cin >> value;
    while (true) {
        if (!cin || cin.peek() != '\n' || value != 0 && value != 1) {
            Console::PrintErrorText(textError);
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> value;
        }
        else {
            return (value);
            break;
        }
    }
}


std::string Verification::getstring(std::string textRequest, std::string textError, size_t length)
{
    std::string nameCS;
    while (true)
    {
        std::cout << textRequest;
        std::cin.seekg(std::cin.eof());
        getline(std::cin, nameCS);
        if (nameCS != "" && checkemptyinput(nameCS) && size(nameCS) <= length)
            return nameCS;
        else
            Console::PrintErrorText(textError);
    }
}

std::set<size_t> Verification::getset(std::string textRequest, std::string textError)
{
    std::set<size_t> filterset;
    size_t value;
    bool flag = true;
    while (flag)
    {
        flag = false;
        std::cout << textRequest;
        while (true)
        {
            std::cin >> value;
            if (std::cin.good())
                filterset.insert(value);
            else
            {
                Console::PrintErrorText(textError);
                filterset.clear();
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                flag = true;
                break;
            }
            if (std::cin.peek() == '\n')
                break;
        }
    }
    return filterset;
}


