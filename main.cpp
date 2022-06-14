#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <windows.h>

#include "ExpensesManager.h"


using namespace std;

void displayExpense(Expense expense)
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
    ExpensesManager expensesManager("C:\\Users\\progg\\Desktop\\Budget\\PersonalBudgetTracker\\expenses.xml",1);

    expensesManager.displayExpenses(20000101,20050101);

    cout << endl << endl;

    cout << expensesManager.getPeriodExpense();



    return 0;
}
