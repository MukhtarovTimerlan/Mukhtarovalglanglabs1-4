// project1Mukhtarov.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <fstream>
#include "CS.h"

using std::cin;
using std::cout;
using std::endl;

struct Pipe
{
    int id = -1, diametr = -1;
    double length = -1;
    bool remont;
};

struct CS
{
    int id = -1, count_of_CS = -1, count_of_CS_in_work = -1, effective = -1;
    std::string name_CS;
}; 

void validateint(int& digitc, int min, int max) {
    while (true) {
        if (!cin || cin.peek() != '\n' || digitc < min || digitc > max)
        {
            cout << "Input error. try again: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> digitc;
        }
        else
        {
            break;
        }
    }
}
void validatedouble(double& digitc, int min, int max) {
    while (true) {
        if (!cin || cin.peek() != '\n' || digitc < min || digitc > max)
        {
            cout << "Input error. try again: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> digitc;
        }
        else
        {
            break;
        }
    }
}


void checkremont(bool& remont)//
{
   while (true) {
        if (!cin || cin.peek() !='\n' || remont != 0 && remont != 1) {
            cout << "Input error. try again: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> remont;
        }
        else {
            break;
        }
    }
}


Pipe input_pipe()
{
    Pipe pipe1;
    system("cls");
    pipe1.id = 0;
    cout << "Input length of pipe in range [10,100] of km - ";
    cin >> pipe1.length;
    validatedouble(pipe1.length,10,100);
    cout << "Input diametr of pipe in range [500,1400] of mm - ";
    cin >> pipe1.diametr;
    validateint(pipe1.diametr,500,1400);
    pipe1.remont = 0;
    return(pipe1);
  }

CS input_CS()
{
    CS CS1;
    system("cls");
    CS1.id = 0;
    cout << "Input name of CS - ";
    cin.ignore(2000, '\n');
    getline(cin, CS1.name_CS);
    cout << "Input count of CS in range of [1,50] ";
    cin >> CS1.count_of_CS;
    validateint(CS1.count_of_CS,1,50);
    cout << "Input count of CS in work - ";
    cin >> CS1.count_of_CS_in_work;
    validateint(CS1.count_of_CS_in_work,1,CS1.count_of_CS_in_work);
    cout << "Input effective in range[0,100] in integers - ";
    cin >> CS1.effective;
    validateint(CS1.effective,1,100);
    return CS1;
}

void output(const Pipe& pipe1)
{
    cout << std::setw(10) << "PIPE\n";
    cout << "---------------------------\n";
    cout << "Length = " << pipe1.length<< '\n';
    cout << "id of pipe = " << pipe1.id << '\n'; 
    cout << "Diametr = " << pipe1.diametr << '\n';
    cout << "Pipe under repair?" << '\n';
    cout << "Yes - 1, No - 0\n"<<std::setw(5) << pipe1.remont << '\n';
}

void output(const CS& CS1)
{
    cout << std::setw(10) << "CS\n";
    cout << "---------------------------\n";
    cout << "id of CS = " << CS1.id << '\n';
    cout << "Name of CS = " << CS1.name_CS << '\n';
    cout << "Count of CS = " << CS1.count_of_CS << '\n';
    cout << "Count of CS in work = " << CS1.count_of_CS_in_work << '\n';
    cout << "Effective of CS = " << CS1.effective << '\n';
}

void savetofilepipe(const Pipe& pipe1, std::ofstream& datfile) {
    if (pipe1.id != -1)// && pipe1.diametr != -1 && pipe1.length != -1)
    {
        datfile << pipe1.id << '\n'
            << pipe1.length << '\n'
            << pipe1.diametr << '\n'
            << pipe1.remont << '\n';
    }
}
void savetofileCS(const CS& CS1, std::ofstream& datfile) {
    if (CS1.id != -1){// && CS1.count_of_CS != -1 && CS1.count_of_CS_in_work != -1 && CS1.effective != -1) {
        datfile << CS1.id << '\n'
            << CS1.name_CS << '\n'
            << CS1.count_of_CS << '\n'
            << CS1.count_of_CS_in_work << '\n'
            << CS1.effective;
    }
}


void savetofile(const CS& CS1, const Pipe& pipe1) {
    std::ofstream datfile("data.txt");
    if (datfile.is_open()){
        savetofilepipe(pipe1, datfile);
        datfile << " \n";
        savetofileCS(CS1, datfile);
        datfile.close();
    }
    else {
        cout << "Error. File is missing or dont exist.\n";
    }
}

void readfromfile(CS& CS1, Pipe& pipe1) {
    std::ifstream dataaread("data.txt");
    if (dataaread.is_open()) {
        if (dataaread.peek() != -1) {
            while (dataaread.peek() != ' ')
            {
                dataaread >> pipe1.id >> pipe1.length >> pipe1.diametr >> pipe1.remont;
                dataaread.ignore(1000, '\n');
            }
            dataaread.ignore(1000, '\n');
            while (dataaread.peek() != -1) {
                dataaread >> CS1.id;
                getline(dataaread, CS1.name_CS);
                dataaread >> CS1.count_of_CS >> CS1.count_of_CS_in_work >> CS1.effective;
            }
            dataaread.close();
        }
        else {
            cout << "You dont load data to file to read it.\n";
        }
    }
    else {
        cout << "File cant be open or empty.";
    }
 }

void changepipe(bool& remont)
{
    system("cls");
    cout << "Pipe under repair?"<<'\n';
    cout << "Yes - 1, No - 0"<<'\n';
    cin >> remont; '\n';
    checkremont(remont);
}

void changeCS(int& count_of_CS_in_work,const int& count_of_CS)
{
    system("cls");
    cout << "Count of CS in work"<<'\n';
    cin >> count_of_CS_in_work; '\n';
    validateint(count_of_CS_in_work,1,count_of_CS);
}

void showobjects(const Pipe& pipe1,const CS& CS1)
{
    system("cls");
   if (pipe1.length == -1 && CS1.count_of_CS == -1) {
        system("cls");
        cout << "Pipe and CS data are empty. Try again after adding info.\n";
    }
    if (pipe1.length !=-1) {
        output(pipe1);
    }
    if (CS1.count_of_CS != -1) {
        output(CS1);
    }
}

void print_menu() {
    system("cls");
    cout << "What do you want to do?" << '\n';
    cout << "1. Add pipe" << '\n';
    cout << "2. Add CS" << '\n';
    cout << "3. Show all objects" << '\n';
    cout << "4. Edit pipe" << '\n';
    cout << "5. Edit CS" << '\n';
    cout << "6. Save to file" << '\n';
    cout << "7. Load from file" << '\n';
    cout << "0. Exit" << '\n';
    cout << ">";
}




int main() {
    Pipe pipe1; CS CS1;
    int variant;
    do {
        print_menu();
        cin >> variant;
        validateint(variant, 0, 7);
        switch (variant) {
        case 0: return 0;
        case 1:
            pipe1 = input_pipe();
            break;

        case 2:
            CS1 = input_CS();
            break;

        case 3:
            showobjects(pipe1,CS1);
            break;

        case 4:
            changepipe(pipe1.remont);
            break;
        case 5:
            changeCS(CS1.count_of_CS_in_work, CS1.count_of_CS);
            break;
        case 6:
            savetofile(CS1, pipe1);
            break;
        case 7:
            readfromfile(CS1, pipe1);
            break; 
        }

        if (variant != 0)
            Sleep(3000);
    } while (true);
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
