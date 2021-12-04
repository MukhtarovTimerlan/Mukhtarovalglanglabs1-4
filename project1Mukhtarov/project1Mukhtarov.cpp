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
#include "GasTransportSystem.h"


using std::cin;
using std::cout;
using std::endl;

size_t Pipe::MaxidPipe = 0;
size_t CS::MaxidCS = 0;
int main() {
    PipeNetwork newPipeNetwork;
    CSNetwork newCSNetwork;
    GasTransportSystem newGasTransportSystem(newPipeNetwork, newCSNetwork);
    int variant;
    do {
        Console::PrintMenu();
        variant = Verification::getint("", "Error input. Only 0-15 numbers", 0, 15);
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
                newPipeNetwork.ShowAllPipes();
            }
            if (querycs == 0) {
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
            system("cls");
            cout << "Banch changing pipes:\n";
            newPipeNetwork.BatchChangePipe();
            break;
        case 7:
            system("cls");
            cout << "Banch changing CS:\n";
            newCSNetwork.BatchChangeCS();
            break;
        case 8:
            system("cls");
            cout << "Deleting Pipe:\n";
            newPipeNetwork.DeletePipe();
            break;
        case 9:
            system("cls");
            cout << "Deleting CS:\n";
            newCSNetwork.DeleteCS();
            break;
        case 10:
        {
            system("CLS");
            Console::PrintTitleText("\n\t\tSaving data to file\n");
            std::string fileName = Verification::getstring("Input name of savefile (.txt, max 30 symbols): ",
                "Error input. Follow the rules!", 30);
            std::ofstream fout(fileName);
            if (fout.is_open())
            {
                newPipeNetwork.SaveToFile(fout);
                fout << ' ' << std::endl;
                newCSNetwork.SaveToFile(fout);
            }
            else
                Console::PrintErrorText("\nERROR!");
            fout.close();
            break;
        }
        case 11:
        {
            system("CLS");
            Console::PrintTitleText("\n\t\tDownloading from file\n");
            std::string fileName = Verification::getstring("Input name of file for download (.txt, less than 30 symbols): ", "Error!", 30);
            std::ifstream fin(fileName);
            if (fin.is_open())
            {
                if (fin.peek() != -1)
                {
                    newPipeNetwork.DownloadFromFile(fin);
                    fin.ignore(10000, '\n');
                    newCSNetwork.DownloadFromFile(fin);
                }
                else
                {
                    Console::PrintErrorText("\nFile is empty ");
                }
            }
            else
                Console::PrintErrorText("\nError");
            fin.close();
            system("pause");
            break;
        }
        case 12: {
            system("cls");
            newGasTransportSystem.ConnectPipe();
            break;
        }
        case 13: {
            system("cls");
            newGasTransportSystem.DisconnectPipe();
            break;
        }
        case 14: {
            system("cls");
            newGasTransportSystem.ShowConnections();
            break;
        }
        case 15: {
            system("cls");
            newGasTransportSystem.SORT(newPipeNetwork, newCSNetwork);
            break;
        }
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
