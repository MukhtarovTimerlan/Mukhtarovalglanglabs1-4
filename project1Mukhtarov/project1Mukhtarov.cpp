// project1Mukhtarov.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

struct Pipe
{
    int id;
    double length, diametr;
};

struct CS
{
    int id, count_of_CS, count_of_CS_in_work;
    wchar_t name_CS;
};

Pipe input_pipe()
{
    Pipe pipe1;
    pipe1.id = 0;
    std::cout << "Input length of pipe - ";
    std::cin >> pipe1.length;
    std::cout << "Input diametr of pipe - ";
    std::cin >> pipe1.diametr;
    return pipe1;
}

CS input_CS()
{
    CS CS1;
    CS1.id = 0;
    std::cout << "Input name of CS - ";
    std::cin >> CS1.name_CS;
    std::cout << "Input count of CS - ";
    std::cin >> CS1.count_of_CS;
    std::cout << "Input count of CS in work - ";
    std::cin >> CS1.count_of_CS_in_work;
    return CS1;
}

void output(Pipe& pipe1)
{
    std::cout << "Length = " << pipe1.length;
    std::cout << "id = " << pipe1.id;
    std::cout << "Diametr = " << pipe1.diametr;
}

void output(CS& CS1)
{
    std::cout << "id of CS = " << CS1.id;
    std::cout << "Name of CS = " << CS1.name_CS;
    std::cout << "Count of CS = " << CS1.count_of_CS;
    std::cout << "Count of CS in work = " << CS1.count_of_CS_in_work;
}

int main()
{
    Pipe pipe1;
    pipe1 = input_pipe();
    output(pipe1);
    CS CS1;
    CS1 = input_CS();
    output(CS1)
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging me

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
