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
    bool remont;
};

struct CS
{
    int id, count_of_CS, count_of_CS_in_work, effective;
    std::string name_CS;
};

void checkdiametr(Pipe& pipe1)
{
    while (true) {
        if (cin.peek() != '\n' || !cin || pipe1.diametr<500 || pipe1.diametr>1400 )
        {
            cout << "input error. try again";
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
            cout << "input error. try again: ";
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
            cout << "input error. try again: ";
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
            cout << "input error. try again: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> CS1.count_of_CS;
        }
        else
            break;
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
    cin >> CS1.name_CS;
    cout << "Input count of CS - ";
    cin >> CS1.count_of_CS;
    checkcountofcs(CS1);
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
    cout << "Pipe under repair?" << '\n';
    cout << "Yes - 1, No - 0" << pipe1.remont << '\n';
}

void output(CS& CS1)
{
    cout << "id of CS = " << CS1.id << '\n';
    cout << "Name of CS = " << CS1.name_CS << '\n';
    cout << "Count of CS = " << CS1.count_of_CS << '\n';
    cout << "Count of CS in work = " << CS1.count_of_CS_in_work << '\n';
    cout << "Effective of CS = " << CS1.effective << '\n';
}

void changepipe(Pipe& pipe1)
{
    system("cls");
    cout << "Pipe under repair?"<<'\n';
    cout << "Yes - 1, No - 0"<<'\n';
    cin >> pipe1.remont; '\n';
}

void changeCS(CS& CS1)
{
    system("cls");
    cout << "Count of CS in work"<<'\n';
    cin >> CS1.count_of_CS_in_work; '\n';
}
void showobjects(Pipe& pipe1, CS& CS1)
{
    system("cls");
    output(pipe1);
    output(CS1);
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
            break;
        case 7:
            break;
       
        }

        if (variant != 0)
            system("pause"); // задерживаем выполнение, чтобы пользователь мог увидеть результат выполнени€ выбранного пункта
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
