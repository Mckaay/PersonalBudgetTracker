#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <windows.h>

#include "ExpensesXMLFile.h"


using namespace std;

void displayExpenses(Expense expense)
{
    cout << "DATE: " <<  expense.getDate() << endl;
    cout << "INT DATE: " << expense.getIntDate() << endl;
    cout << "USER_ID: " << expense.getUserId() << endl;
    cout << "EXPENSE_ID: " <<expense.getId() << endl;
    cout << "EXPENSE_DESCIRPTION: " << expense.getDescription() << endl;
    cout << "AMOUNT: " <<expense.getAmount() << endl;
}


int main()
{
    ExpensesXMLFile expensesXMLFile("C:\\Users\\progg\\Desktop\\Budget\\PersonalBudgetTracker\\expenses.xml");

    vector <Expense> expenses = expensesXMLFile.loadExpensesFromXMLFileToVector(1);

    sort(expenses.begin(),expenses.end());

    for(auto it1 = expenses.begin(); it1 != expenses.end(); it1++)
    {
        displayExpenses(*it1);
    }

    cout << expensesXMLFile.getLastExpenseId();




    return 0;
}
