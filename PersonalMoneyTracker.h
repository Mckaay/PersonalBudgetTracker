#ifndef PERSONALMONEYTRACKER_H
#define PERSONALMONEYTRACKER_H


#include "UserManager.h"
#include "IncomesManager.h"
#include "ExpensesManager.h"

using namespace std;

class PersonalMoneyTracker
{
    UserManager userManager;

public:
    PersonalMoneyTracker(string usersFileRoot): userManager(usersFileRoot) {};

    void registration();
    void loggingIn();
    void changePassword();
    void logout();




};



#endif // PERSONALMONEYTRACKER_H
