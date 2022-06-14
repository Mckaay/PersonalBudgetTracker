#ifndef EXPENSESMANAGER_H
#define EXPENSESMANAGER_H

#include "ExpensesXMLFile.h"


using namespace std;

class ExpensesManager
{
    const int LOGGED_IN_USER_ID;
    vector <Expense> expenses;
    ExpensesXMLFile expensesXMLFile;
    double periodExpense;

    void displayExpense(Expense expense);

public:
    ExpensesManager(string fileRoot,int loggedInUserId): expensesXMLFile(fileRoot), LOGGED_IN_USER_ID(loggedInUserId)
    {
        periodExpense = 0;
        expenses = expensesXMLFile.loadExpensesFromXMLFileToVector(LOGGED_IN_USER_ID);
        sort(expenses.begin(),expenses.end());
    };
    void addExpense();
    void displayExpenses(int firstDate,int secondDate);
    double getPeriodExpense();

};



#endif
