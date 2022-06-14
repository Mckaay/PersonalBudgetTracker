#include "IncomesManager.h"

void IncomesManager::addIncome()
{
    Income income;

    income.setUserId(LOGGED_IN_USER_ID);
    income.setId(incomesXMLFile.getLastIncomeId());

    cout << "Wybierz date przychodu" << endl;
    cout << "1. Dzisiejsza data" << endl;
    cout << "2. Wczesniejsza data" << endl;
    char decision;
    cin >> decision;

    if(decision == '1')
    {
        income.setDate(Time::getCurrentDate());
        income.setIntDate(Time::convertStringDateToIntDate(income.getDate()));
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
        income.setDate(date);
        income.setIntDate(Time::convertStringDateToIntDate(date));
    }

    string description;
    cout << endl << "Podaj opis przychodu: ";
    cin >> description;
    income.setDescription(description);

    int amount;
    cout << endl << "Podaj kwote: ";
    cin >> amount;
    income.setAmount(amount);

    incomesXMLFile.saveIncomeToXMLFile(income);
    incomes.push_back(income);

    sort(incomes.begin(),incomes.end());
}


void IncomesManager::displayIncome(Income income)
{
    cout << "DATE: " <<  income.getDate() << endl;
    cout << "INT DATE: " << income.getIntDate() << endl;
    cout << "USER_ID: " << income.getUserId() << endl;
    cout << "INCOME_ID: " <<income.getId() << endl;
    cout << "INCOME_DESCIRPTION: " << income.getDescription() << endl;
    cout << "AMOUNT: " <<income.getAmount() << endl;
}


void IncomesManager::displayIncomes(int firstDate,int secondDate)
{
    periodIncome = 0;
    for(auto it1 = incomes.begin(); it1 != incomes.end(); it1++)
    {
        if(it1->getIntDate() >= firstDate && it1->getIntDate() <= secondDate)
        {
            periodIncome += it1->getAmount();
            displayIncome(*it1);
        }
    }
}

double IncomesManager::getPeriodIncome()
{
    return this->periodIncome;
}
