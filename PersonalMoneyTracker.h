#ifndef PERSONALMONEYTRACKER_H
#define PERSONALMONEYTRACKER_H


#include "UserManager.h"
#include "IncomesManager.h"
#include "ExpensesManager.h"

using namespace std;

class PersonalMoneyTracker
{
    UserManager userManager;
    IncomesManager* incomesManager;
    ExpensesManager* expensesManager;

    const string INCOMES_XML_FILE_ROOT;
    const string EXPENSES_XML_FILE_ROOT;


public:
    PersonalMoneyTracker(string usersFileRoot,string incomesFileRoot,string expensesFileRoot): userManager(usersFileRoot), INCOMES_XML_FILE_ROOT(incomesFileRoot), EXPENSES_XML_FILE_ROOT(expensesFileRoot)
    {
        incomesManager = NULL;
        expensesManager = NULL;
    };
    ~PersonalMoneyTracker()
    {
        delete incomesManager;
        delete expensesManager;
        incomesManager = NULL;
        expensesManager = NULL;
    }
    int getLoggedInUserId();
    void registration();
    void loggingIn();
    void changePassword();
    void logout();
    void addIncome();
    void addExpense();
    void displaySummary();
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    void displayPeriodBalance();
    void displayMainMenu();
    char displayLoginMenu();
};



#endif // PERSONALMONEYTRACKER_H
