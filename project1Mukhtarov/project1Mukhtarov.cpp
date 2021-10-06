// project1Mukhtarov.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;

struct Pipe
{
    int id=-1;
    double length = -1, diametr=-1;
    bool remont;
};

struct CS
{
    int id=-1, count_of_CS = -1, count_of_CS_in_work=-1, effective=-1;
    std::string name_CS;
};

void checkdiametr(Pipe& pipe1)
{
    while (true) {
        if (cin.peek() != '\n' || !cin || pipe1.diametr<500 || pipe1.diametr>1400 )
        {
            cout << "Input error. try again: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> pipe1.diametr;       
        }
        else
        {
            break;
        }
    }
}
void checklength(Pipe& pipe1)
{
    while (true) {
        if (cin.peek() != '\n' || !cin || pipe1.length < 10 || pipe1.length>100)
        {
            cout << "Input error. try again: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> pipe1.length;
        }
        else
        {
            break;
        }
    }
}
void checkremont(Pipe& pipe1)
{
    while (true) {
        if (cin.peek() !='\n' || !cin || pipe1.remont != 0 && pipe1.remont != 1) {
            cout << "Input error. try again: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> pipe1.remont;
        }
        else {
            break;
        }
    }
}

void checkcountofcs(CS& CS1) {
    while (true) {
        if (cin.peek() != '\n' || !cin || CS1.count_of_CS < 1) {
            cout << "Input error. try again: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> CS1.count_of_CS;
        }
        else
            break;
    }
}
void checkcountofcsinwork(CS& CS1) {
    while (true) {
        if (cin.peek() != '\n' || !cin || CS1.count_of_CS_in_work < 1 || CS1.count_of_CS_in_work>CS1.count_of_CS) {
            cout << "Input error. try again: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> CS1.count_of_CS_in_work;
        }
        else
            break;
    }
}
void checkeffective(CS& CS1)
{
    while (true) {
        if (cin.peek() != '\n' || !cin || CS1.effective < 0 || CS1.effective > 100)
        {
            cout << "Input error. try again: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> CS1.effective;
        }
        else
        {
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
    checklength(pipe1);
    cout << "Input diametr of pipe in range [500,1400] of mm - ";
    cin >> pipe1.diametr;
    checkdiametr(pipe1);
    cout << "Pipe under repair?"<<'\n';
    cout << "Yes - 1, No - 0"<<'\n';
    cout << ">";
    cin >> pipe1.remont;
    checkremont(pipe1);
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
    cout << "Input count of CS - ";
    cin >> CS1.count_of_CS;
    checkcountofcs(CS1);
    cout << "Input count of CS in work - ";
    cin >> CS1.count_of_CS_in_work;
    checkcountofcsinwork(CS1);
    cout << "Input effective in range[0,100] in integers - ";
    cin >> CS1.effective;
    checkeffective(CS1);
    return CS1;
}

void output(Pipe& pipe1)
{
    cout << std::setw(10) << "PIPE\n";
    cout << "---------------------------\n";
    cout << "Length = " << pipe1.length<< '\n';
    cout << "id of pipe = " << pipe1.id << '\n'; 
    cout << "Diametr = " << pipe1.diametr << '\n';
    cout << "Pipe under repair?" << '\n';
    cout << "Yes - 1, No - 0\n"<<std::setw(5) << pipe1.remont << '\n';
}

void output(CS& CS1)
{
    cout << std::setw(10) << "CS\n";
    cout << "---------------------------\n";
    cout << "id of CS = " << CS1.id << '\n';
    cout << "Name of CS = " << CS1.name_CS << '\n';
    cout << "Count of CS = " << CS1.count_of_CS << '\n';
    cout << "Count of CS in work = " << CS1.count_of_CS_in_work << '\n';
    cout << "Effective of CS = " << CS1.effective << '\n';
}

void savetofile(const CS& CS1, const Pipe& pipe1) {
    std::ofstream Timerlanfile("data.txt");
    if (Timerlanfile.is_open()){
        if (pipe1.id != -1 && pipe1.diametr != -1 && pipe1.length != -1)
        {
            Timerlanfile << pipe1.id << '\n'
                << pipe1.length << '\n'
                << pipe1.diametr << '\n'
                << pipe1.remont << '\n';
        }
        Timerlanfile << " \n";
        if (CS1.id != -1 && CS1.count_of_CS != -1 && CS1.count_of_CS_in_work != -1 && CS1.effective != -1) {
            Timerlanfile << CS1.id << '\n'
                << CS1.name_CS << '\n'
                << CS1.count_of_CS << '\n'
                << CS1.count_of_CS_in_work << '\n'
                << CS1.effective;
        }
        Timerlanfile.close();
    }
    else {
        cout << "Error. File is missing or dont exist.\n";
    }




}
void readfromfile(CS& CS1, Pipe& pipe1) {
    std::ifstream timerlaread("data.txt");
    if (timerlaread.is_open()) {
        if (timerlaread.peek() != -1) {
            while (timerlaread.peek() != ' ')
            {
                timerlaread >> pipe1.id >> pipe1.length >> pipe1.diametr >> pipe1.remont;
                timerlaread.ignore(1000, '\n');
            }
            timerlaread.ignore(1000, '\n');
            while (timerlaread.peek() != -1) {
                timerlaread >> CS1.id;
                getline(timerlaread, CS1.name_CS);
                timerlaread >> CS1.count_of_CS >> CS1.count_of_CS_in_work >> CS1.effective;
            }
            timerlaread.close();
        }
        else {
            cout << "You dont load data to file to read it.\n";
        }
    }
    else {
        cout << "File cant be open or empty.";
    }
 }

Pipe changepipe(Pipe& pipe1)
{
    system("cls");
    cout << "Pipe under repair?"<<'\n';
    cout << "Yes - 1, No - 0"<<'\n';
    cin >> pipe1.remont; '\n';
    checkremont(pipe1);
    return (pipe1);
}

CS changeCS(CS& CS1)
{
    system("cls");
    cout << "Count of CS in work"<<'\n';
    cin >> CS1.count_of_CS_in_work; '\n';
    checkcountofcsinwork(CS1);
    return(CS1);
}
void showobjects(Pipe& pipe1, CS& CS1)
{
   // if (pipe1.length == -1 || CS1.count_of_CS == -1) {
   //     system("cls");
    //    cout << "Pipe and/or CS data are empty. Try again after adding info.\n";
   // }
   // else {
        system("cls");
        cout << "If properties are -1 then CS or Pipe aren't inputen\n";
        output(pipe1);
        output(CS1);
    //}
}

void print_menu() {
    system("cls"); // очищаю экран
    cout << "What do you want to do?" << '\n';
    cout << "1. Add pipe" << '\n';
    cout << "2. Add CS" << '\n';
    cout << "3. Show all objects" << '\n';
    cout << "4. Edit pipe" << '\n';
    cout << "5. Edit CS" << '\n';
    cout << "6. Save changes" << '\n';
    cout << "7. Load to file" << '\n';
    cout << "0. Exit" << '\n';
    cout << ">";
}




int main() {
    Pipe pipe1; CS CS1;
    int variant;
    do {
        print_menu(); // выводим меню на экран
        cin >> variant;
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
            changepipe(pipe1);
            break;
        case 5:
            changeCS(CS1);
            break;
        case 6:
            savetofile(CS1, pipe1);
            break;
        case 7:
            readfromfile(CS1, pipe1);
            break;
        default:
            cout << "It isn't command number. Try again.\n";
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
