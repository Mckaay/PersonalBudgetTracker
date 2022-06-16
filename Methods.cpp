#include "Methods.h"

void Methods::pauseProgram()
{
    cout << "Nacisnij dowolny przycisk by powrocic do Menu Glownego" << endl;
    getch();
    system("cls");
}

bool Methods::isChar(char c)
{
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return true;
    else return false;
}

string Methods::loadLine()
{
    string input = "";
    cin.sync();
    getline(cin, input);
    return input;
}

string Methods::intToString(int integer)
{
    ostringstream ss;
    ss << integer;
    string str = ss.str();
    return str;
}

