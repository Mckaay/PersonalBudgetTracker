#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <windows.h>

#include "IncomesManager.h"
#include "PersonalMoneyTracker.h"



using namespace std;

int main()
{
    PersonalMoneyTracker personalMoneyTracker("C:\\Users\\progg\\Desktop\\Budget\\PersonalBudgetTracker\\Users.xml","C:\\Users\\progg\\Desktop\\Budget\\PersonalBudgetTracker\\incomes.xml");

    personalMoneyTracker.loggingIn();

    personalMoneyTracker.displayPreviousMonthBalance();

    personalMoneyTracker.logout();

    cout << endl << endl;

    personalMoneyTracker.loggingIn();

    personalMoneyTracker.displayPreviousMonthBalance();

    return 0;
}
