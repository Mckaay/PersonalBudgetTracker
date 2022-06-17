#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
#include <map>
#include <string>
#include "Methods.h"

using namespace std;

class Time
{
    static const int MIN_DATE = 20000101;

public:
    static string getCurrentDate();
    static bool checkIfValidDate(int date);
    static bool isLeapYear(int year);
    static int daysInAMonth(int monthNumber,bool leapYear);
    static int convertStringDateToIntDate(string date);
    static int getYearFromDate(string date);
    static int getMonthFromDate(string date);
    static int getDayFromDate(string date);
    static int currentMaxDate();
    static string convertIntDateToStringDate(int date);
    static string getPreviousMonthStartDate();
    static string getPreviousMonthEndDate();

};

#endif
