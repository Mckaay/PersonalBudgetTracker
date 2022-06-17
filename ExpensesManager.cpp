#include "ExpensesManager.h"

void ExpensesManager::addExpense()
{
    Expense expense;

    expense.setUserId(LOGGED_IN_USER_ID);
    expense.setId(expensesXMLFile.getLastExpenseId()+1);
    expensesXMLFile.setLastExpenseId(expense.getId());

    cout << "Podaj date: " << endl;
    cout << "1. Dzisiejsza data" << endl;
    cout << "2. Inna data" << endl;
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
        cout << "Podaj  inna date: ";
        cin >> date;
        bool valid = Time::checkIfValidDate(Time::convertStringDateToIntDate(date));

        while(!valid)
        {
            cout << "Podana data jest niepoprawna! Sprobuj ponownie" << endl;
            cout << "Podaj inna date: ";
            cin >> date;
            valid = Time::checkIfValidDate(Time::convertStringDateToIntDate(date));
        }
        expense.setDate(date);
        expense.setIntDate(Time::convertStringDateToIntDate(date));
    }

    string description;
    cout << endl << "Podaj opis wydatku: ";
    description = Methods::loadLine();
    expense.setDescription(description);

    string amount;
    cout << "Podaj kwote: ";
    cin >> amount;
    expense.setAmount(Methods::commaToDotSwap(amount));

    expensesXMLFile.saveExpenseToXMLFile(expense);
    expenses.push_back(expense);

    sort(expenses.begin(),expenses.end());
}


void ExpensesManager::displayExpense(Expense expense)
{
    cout << endl;
    cout << "DATA:        " <<  expense.getDate() << endl;
    cout << "OPIS:         " << expense.getDescription() << endl;
    cout << "KWOTA:          " << expense.getAmount() << endl;
    cout << "-----------------------------------------" << endl;
    cout << endl;
}

void ExpensesManager::displayExpenses(int firstDate,int secondDate)
{
    periodExpense = 0;
    cout << "-------------LISTA_WYDATKOW-----------------" << endl;
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
