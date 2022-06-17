#ifndef METHODS_H
#define METHODS_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <windows.h>
#include <conio.h>
#include <algorithm>
#include <cstdio>

using namespace std;

class Methods
{
public:
    static string loadLine();
    static bool isChar(char c);
    static void pauseProgram();
    static string intToString(int integer);
    static double commaToDotSwap(string amount);
    static string doubleToStringWithPrecision(double amount);

};

#endif
