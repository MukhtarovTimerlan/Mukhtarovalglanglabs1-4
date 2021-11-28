// project1Mukhtarov.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <fstream>
#include "Console.h"
#include "Verification.h"
#include "PipeNetwork.h"
#include "CSNetwork.h"
#include "CS.h"
#include "Pipe.h"


using std::cin;
using std::cout;
using std::endl;

/*void savetofilepipe(const Pipe& pipe1, std::ofstream& datfile) {
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


/*void savetofile(const CS& CS1, const Pipe& pipe1) {
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

/*void readfromfile(CS& CS1, Pipe& pipe1) {
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
}*/
size_t Pipe::MaxidPipe = 0;
size_t CS::MaxidCS = 0;
int main() {
    PipeNetwork newPipeNetwork;
    CSNetwork newCSNetwork;
    int variant;
    do {
        Console::PrintMenu();
        variant = Verification::getint("", "Error input. Only 0-7 numbers", 0, 7);
        switch (variant) {
        case 0: return 0;
        case 1:
            system("CLS");
            Console::PrintTitleText("Adding pipe");
            newPipeNetwork.AddPipe();
            break;

        case 2:
            system("CLS");
            Console::PrintTitleText("Adding CS");
            newCSNetwork.AddCS();
            break;

        case 3:
            system("CLS");
            bool querypipe, querycs;
            querypipe = newPipeNetwork.emptyPnetwork();
            querycs = newCSNetwork.emptyCnetwork();
            if (querypipe == 1 && querycs == 1)
                cout << "Pipes and CS aren't inputten";
            if (querypipe == 0) {
                cout << "All pipes:\n";
                newPipeNetwork.ShowAllPipes();
            }
            if (querycs == 0) {
                cout << "All CS:\n";
                newCSNetwork.ShowAllCS();
            }
            break;

        case 4:
            system("cls");
            newPipeNetwork.changePipe();
            break;
        case 5:
            system("cls");
            newCSNetwork.ChangeCS();
            break;
        case 6:
            /*savetofile(CS1, pipe1);
            */break;
        case 7:
            /*readfromfile(CS1, pipe1);
             */break;
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
