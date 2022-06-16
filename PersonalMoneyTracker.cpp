#include "PersonalMoneyTracker.h"

void PersonalMoneyTracker::registration()
{
    userManager.registration();
}

void PersonalMoneyTracker::loggingIn()
{
    userManager.loggingIn();

    if(userManager.getLoggedinUserId())
    {
        incomesManager = new IncomesManager(INCOMES_XML_FILE_ROOT,userManager.getLoggedinUserId());
    }
}

void PersonalMoneyTracker::changePassword()
{
    userManager.changePassword();
}

void PersonalMoneyTracker::logout()
{
    delete incomesManager;
    incomesManager = NULL;
    userManager.logout();
}

void PersonalMoneyTracker::addIncome()
{
    incomesManager->addIncome();
}

void PersonalMoneyTracker::displayCurrentMonthBalance()
{
    incomesManager->displayIncomes((Time::convertStringDateToIntDate(Time::getCurrentDate())/100)*100+1,Time::currentMaxDate());
}

void PersonalMoneyTracker::displayPreviousMonthBalance()
{
    incomesManager->displayIncomes(Time::convertStringDateToIntDate(Time::getPreviousMonthStartDate()),Time::convertStringDateToIntDate(Time::getPreviousMonthEndDate()));
}




