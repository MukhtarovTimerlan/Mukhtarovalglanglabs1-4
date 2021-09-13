// project1Mukhtarov.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
struct Pipe
{
    int id;
    double length;
};

void input(Pipe& pipe1);

void output(Pipe& pipe1);

int main()
{
    Pipe pipe1;
    pipe1.id = 0;
    input(pipe1);
    output(pipe1);
}

void output(Pipe& pipe1)
{
    std::cout << "Length = " << pipe1.length;
    std::cout << "\nid = " << pipe1.id;
}

void input(Pipe& pipe1)
{
    std::cout << "Input length's pipe - ";
    std::cin >> pipe1.length;
    std::cout << "Input id pipe - ";
    std::cin >> pipe1.id;
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
