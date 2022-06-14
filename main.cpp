#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <windows.h>

#include "IncomesManager.h"


using namespace std;

int main()
{
    IncomesManager incomesManager("C:\\Users\\progg\\Desktop\\Budget\\PersonalBudgetTracker\\incomes.xml",1);

    incomesManager.displayIncomes(20000101,20050101);

    cout << endl << endl;

    cout << incomesManager.getPeriodIncome();



    return 0;
}
