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
    const string INCOMES_XML_FILE_ROOT;


public:
    PersonalMoneyTracker(string usersFileRoot,string incomesFileRoot): userManager(usersFileRoot), INCOMES_XML_FILE_ROOT(incomesFileRoot)
    {
        incomesManager = NULL;
    };
    ~PersonalMoneyTracker()
    {
        delete incomesManager;
        incomesManager = NULL;
    }
    void registration();
    void loggingIn();
    void changePassword();
    void logout();
    void addIncome();
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();





};



#endif // PERSONALMONEYTRACKER_H
