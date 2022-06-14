#include "ExpensesManager.h"

void ExpensesManager::addExpense()
{
    Expense expense;

    expense.setUserId(LOGGED_IN_USER_ID);
    expense.setId(expensesXMLFile.getLastExpenseId());

    cout << "Wybierz date wydatku" << endl;
    cout << "1. Dzisiejsza data" << endl;
    cout << "2. Wczesniejsza data" << endl;
    char decision;
    cin >> decision;

    if(decision == '1')
    {
        expense.setDate(Time::getCurrentDate());
        expense.setIntDate(Time::convertStringDateToIntDate(expense.getDate()));
    }
    else if(decision == '2')
    {
        string date;
        cout << "Podaj  wczesniejsza date: ";
        cin >> date;
        bool valid = Time::checkIfValidDate(Time::convertStringDateToIntDate(date));

        while(!valid)
        {
            cout << "Podana data jest niepoprawna! Sprobuj ponownie" << endl;
            cin >> date;
            valid = Time::checkIfValidDate(Time::convertStringDateToIntDate(date));
        }
        expense.setDate(date);
        expense.setIntDate(Time::convertStringDateToIntDate(date));
    }

    string description;
    cout << endl << "Podaj opis wydatku: ";
    cin >> description;
    expense.setDescription(description);

    int amount;
    cout << endl << "Podaj kwote: ";
    cin >> amount;
    expense.setAmount(amount);

    expensesXMLFile.saveExpenseToXMLFile(expense);
    expenses.push_back(expense);

    sort(expenses.begin(),expenses.end());
}


void ExpensesManager::displayExpense(Expense expense)
{
    cout << "DATE: " <<  expense.getDate() << endl;
    cout << "INT DATE: " << expense.getIntDate() << endl;
    cout << "USER_ID: " << expense.getUserId() << endl;
    cout << "EXPENSE_ID: " <<expense.getId() << endl;
    cout << "EXPENSE_DESCIRPTION: " << expense.getDescription() << endl;
    cout << "AMOUNT: " <<expense.getAmount() << endl;
}


void ExpensesManager::displayExpenses(int firstDate,int secondDate)
{
    periodExpense = 0;
    for(auto it1 = expenses.begin(); it1 != expenses.end(); it1++)
    {
        if(it1->getIntDate() >= firstDate && it1->getIntDate() <= secondDate)
        {
            periodExpense += it1->getAmount();
            displayExpense(*it1);
        }
    }
}

double ExpensesManager::getPeriodExpense()
{
    return this->periodExpense;
}
