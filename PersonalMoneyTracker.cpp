#include "PersonalMoneyTracker.h"



int PersonalMoneyTracker::getLoggedInUserId()
{
    return userManager.getLoggedinUserId();
}

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
        expensesManager = new ExpensesManager(EXPENSES_XML_FILE_ROOT,userManager.getLoggedinUserId());
    }
}

void PersonalMoneyTracker::changePassword()
{
    userManager.changePassword();
}

void PersonalMoneyTracker::logout()
{
    delete incomesManager;
    delete expensesManager;
    incomesManager = NULL;
    expensesManager = NULL;
    userManager.logout();
}

void PersonalMoneyTracker::addIncome()
{
    incomesManager->addIncome();
}

void PersonalMoneyTracker::addExpense()
{
    expensesManager->addExpense();
}

void PersonalMoneyTracker::displayCurrentMonthBalance()
{
    incomesManager->displayIncomes((Time::convertStringDateToIntDate(Time::getCurrentDate())/100)*100+1,Time::currentMaxDate());
    expensesManager->displayExpenses((Time::convertStringDateToIntDate(Time::getCurrentDate())/100)*100+1,Time::currentMaxDate());

    cout << "         SUMA PRZYCHODOW: " <<  incomesManager->getPeriodIncome() << endl;
    cout << "         SUMA WYDATKOW:   " <<  expensesManager->getPeriodExpense() << endl;
    cout << "           BILANS: " <<  incomesManager->getPeriodIncome() - expensesManager->getPeriodExpense() << endl << endl;
}

void PersonalMoneyTracker::displayPreviousMonthBalance()
{
    incomesManager->displayIncomes(Time::convertStringDateToIntDate(Time::getPreviousMonthStartDate()),Time::convertStringDateToIntDate(Time::getPreviousMonthEndDate()));
    expensesManager->displayExpenses(Time::convertStringDateToIntDate(Time::getPreviousMonthStartDate()),Time::convertStringDateToIntDate(Time::getPreviousMonthEndDate()));

    cout << "         SUMA PRZYCHODOW: "  << incomesManager->getPeriodIncome() << endl;
    cout << "         SUMA WYDATKOW:   "  << expensesManager->getPeriodExpense() << endl;
    cout << "           BILANS: "  << incomesManager->getPeriodIncome() - expensesManager->getPeriodExpense() << endl << endl;
}

void PersonalMoneyTracker::displayPeriodBalance()
{
    string firstDate, secondDate;
    bool validFirstDate, validSecondDate;

    cout << "Podaj poczatkowa date: ";
    firstDate = Methods::loadLine();
    validFirstDate = Time::checkIfValidDate(Time::convertStringDateToIntDate(firstDate));
    while(!validFirstDate)
    {
        cout << "Niestety podana data jest nieprawidlowa! Sprobuj ponownie!" << endl;
        cout << "Data powinna zawierac sie w przedziale od 2000-01-01 do " << Time::convertIntDateToStringDate(Time::currentMaxDate()) << endl;
        cout << "Podaj date ponownie: ";
        firstDate = Methods::loadLine();
        validFirstDate = Time::checkIfValidDate(Time::convertStringDateToIntDate(firstDate));
    }
    cout << "Podaj koncowa date: ";
    secondDate = Methods::loadLine();
    validSecondDate = Time::checkIfValidDate(Time::convertStringDateToIntDate(secondDate));

    if(validSecondDate)
    {
        if(Time::convertStringDateToIntDate(firstDate) > Time::convertStringDateToIntDate(secondDate))
        {
            cout << "Blednie podane daty! Pierwsza jest pozniejsza niz druga!" << endl;
            validSecondDate = false;
        }
    }


    while(!validSecondDate)
    {
        cout << "Niestety podana data jest nieprawidlowa! Sprobuj ponownie!" << endl;
        cout << "Data powinna zawierac sie w przedziale od " << firstDate << " do " << Time::convertIntDateToStringDate(Time::currentMaxDate()) << endl;
        cout << "Podaj date ponownie: ";
        secondDate = Methods::loadLine();
        validSecondDate = Time::checkIfValidDate(Time::convertStringDateToIntDate(secondDate));

        if(Time::convertStringDateToIntDate(firstDate) > Time::convertStringDateToIntDate(secondDate))
        {
            cout << "Blednie podane daty! Pierwsza jest pozniejsza niz druga!" << endl;
            validSecondDate = false;
        }
    }

    incomesManager->displayIncomes(Time::convertStringDateToIntDate(firstDate),Time::convertStringDateToIntDate(secondDate));
    expensesManager->displayExpenses(Time::convertStringDateToIntDate(firstDate),Time::convertStringDateToIntDate(secondDate));

    cout << "         SUMA PRZYCHODOW: "  << incomesManager->getPeriodIncome() << endl;
    cout << "         SUMA WYDATKOW:   "  << expensesManager->getPeriodExpense() << endl;
    cout << "           BILANS: "  << incomesManager->getPeriodIncome() - expensesManager->getPeriodExpense() << endl << endl;
}

void PersonalMoneyTracker::displayMainMenu()
{
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
}

char PersonalMoneyTracker::displayLoginMenu()
{
    return userManager.loginMenu();
}




