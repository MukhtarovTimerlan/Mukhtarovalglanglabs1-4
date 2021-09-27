// project1Mukhtarov.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

struct Pipe
{
    int id;
    double length, diametr;
};

struct CS
{
    int id, count_of_CS, count_of_CS_in_work, effective;
    std::string name_CS;
};

Pipe input_pipe()
{
    Pipe pipe1;
    pipe1.id = 0;
    cout << "Input length of pipe - ";
    cin >> pipe1.length;
    cout << "Input diametr of pipe - ";
    cin >> pipe1.diametr;
    return pipe1;
}

CS input_CS()
{
    CS CS1;
    CS1.id = 0;
    cout << "Input name of CS - ";
    cin >> CS1.name_CS;
    cout << "Input count of CS - ";
    cin >> CS1.count_of_CS;
    cout << "Input count of CS in work - ";
    cin >> CS1.count_of_CS_in_work;
    cout << "Input effective - ";
    cin >> CS1.effective;
    return CS1;
}

void output(Pipe& pipe1)
{
    cout << "Length = " << pipe1.length<< '\n';
    cout << "id of pipe = " << pipe1.id << '\n';
    cout << "Diametr = " << pipe1.diametr << '\n';
}

void output(CS& CS1)
{
    cout << "id of CS = " << CS1.id << '\n';
    cout << "Name of CS = " << CS1.name_CS << '\n';
    cout << "Count of CS = " << CS1.count_of_CS << '\n';
    cout << "Count of CS in work = " << CS1.count_of_CS_in_work << '\n';
    cout << "Effective of CS = " << CS1.effective << '\n';
}

void print_menu() {
    system("cls"); // очищаем экран
    cout << "What do you want to do?" << endl;
    cout << "1. Add pipe" << endl;
    cout << "2. Add CS" << endl;
    cout << "3. Show all objects" << endl;
    cout << "4. Edit pipe" << endl;
    cout << "5. Edit CS" << endl;
    cout << "6. Save changes" << endl;
    cout << "7. Load to file" << endl;
    cout << "0. Exit" << endl;
    cout << ">";
}

Pipe change_pipe(pipe1)
{
        input_pipe();
        cout << "Pipe after change" << '\n';
        output(pipe1);

}

int main()
{
    print_menu();
    Pipe pipe1;
    pipe1 = input_pipe();
    output(pipe1);
    CS CS1;
    CS1 = input_CS();
    output(CS1);
    pipe1 change_pipe();
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
