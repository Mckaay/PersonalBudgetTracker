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

double Methods::commaToDotSwap(string amount)
{
    size_t found = amount.find(",");
    if(found != string::npos)
    {
        amount.replace(found,1,".");
    }
    return stod(amount);
}

string Methods::doubleToStringWithPrecision(double amount)
{
    std::ostringstream streamObj3;
    streamObj3 << std::fixed;
    streamObj3 << std::setprecision(2);
    streamObj3 << amount;
    std::string strObj3 = streamObj3.str();

    return strObj3;
}

