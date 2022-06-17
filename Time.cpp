#include "Time.h"

string Time::getCurrentDate()
{
    time_t currentTime = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&currentTime);
    strftime(buf,sizeof(buf),"%Y-%m-%d", &tstruct);
    string str(buf);
    return str;
}

bool Time::checkIfValidDate(int date)
{
    const int MIN_DATE = 20000101;
    const int MAX_DATE = currentMaxDate();

    string strDate = convertIntDateToStringDate(date);

    int year = getYearFromDate(strDate);
    int month = getMonthFromDate(strDate);
    int days = getDayFromDate(strDate);
    bool isLeap = isLeapYear(year);

    if(date < MIN_DATE || date > MAX_DATE) return false;
    else if(days < 1 || days > daysInAMonth(month,isLeap)) return false;
    else if(month < 1 || month > 12) return false;
    else return true;
}

int Time::currentMaxDate()
{
    string currentDate = getCurrentDate();
    int maxDay = daysInAMonth(getMonthFromDate(currentDate),isLeapYear(getYearFromDate(currentDate)));

    currentDate.replace(currentDate.rfind("-")+1,2, to_string(maxDay));
    return convertStringDateToIntDate(currentDate);
}


int Time::convertStringDateToIntDate(string date)
{
    date.erase(date.find("-"),1);
    date.erase(date.rfind("-"),1);

    return stoi(date);
}

string Time::convertIntDateToStringDate(int date)
{
    string strDate = Methods::intToString(date);
    strDate.insert(4,"-");
    strDate.insert(7,"-");
    return strDate;

}

bool Time::isLeapYear(int year)
{
    if(((year % 4 == 0) && (year % 100 !=0)) || (year % 400 == 0)) return true;
    else return false;
}

int Time::getYearFromDate(string date)
{
    return stoi(date.substr(0,4));
}

int Time::getMonthFromDate(string date)
{
    return stoi(date.substr(5,2));
}

int Time::getDayFromDate(string date)
{
    return stoi(date.substr(8,2));
}

int Time::daysInAMonth(int monthNumber,bool leapYear)
{
    const int FEBRUARY_MONTH_NUMBER = 2;
    const int LEAP_YEAR_FEBRUARY_DAYS = 29;

    map<int,int> dayInAMonth = {{1,31},{2,28},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31}};
    if(leapYear && monthNumber == FEBRUARY_MONTH_NUMBER) return LEAP_YEAR_FEBRUARY_DAYS;
    else return dayInAMonth.find(monthNumber)->second;
}

string Time::getPreviousMonthStartDate()
{
    string currentDate = getCurrentDate();
    int intCurrentDate = convertStringDateToIntDate(currentDate);
    if(getMonthFromDate(currentDate)!= 1) intCurrentDate = ((intCurrentDate - 100)/100)*100+1;
    else intCurrentDate = ((intCurrentDate /10000)*10000+ 1200 + 1) - 10000;

    return convertIntDateToStringDate(intCurrentDate);
}

string Time::getPreviousMonthEndDate()
{
    string previousMonth = getPreviousMonthStartDate();
    int previousIntMonth = convertStringDateToIntDate(previousMonth);
    previousIntMonth = (previousIntMonth/100)*100 + daysInAMonth(getMonthFromDate(previousMonth),isLeapYear(getYearFromDate(previousMonth)));
    return convertIntDateToStringDate(previousIntMonth);
}

