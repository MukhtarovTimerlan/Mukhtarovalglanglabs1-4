#include "Console.h"
using std::cout;
using std::endl;

void Console::PrintMenu()
{
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

void Console::PrintErrorText(std::string textError)
{
    cout << textError << endl;
}

void Console::PrintTitleText(std::string textTitle)
{
    cout << textTitle << endl;
}

