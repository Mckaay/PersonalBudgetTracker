#include "IncomesManager.h"

void IncomesManager::addIncome()
{
    Income income;

    income.setUserId(LOGGED_IN_USER_ID);
    income.setId(incomesXMLFile.getLastIncomeId()+1);

    incomesXMLFile.setLastIncomeId(income.getId());


    cout << " >>>>>> DODAWANIE NOWEGO PRZYCHODU <<<<<<< " << endl << endl;
    cout << "Wybierz z menu kiedy otrzymano przychod" << endl << endl;

    cout << "1. Dzisiejszy przychod" << endl;
    cout << "2. Przychod z innego dnia" << endl;
    cout << "3. Powrot do menu" << endl;

    char decision;
    cout << "Twoj wybor: ";
    cin >> decision;

    if(decision == '1')
    {
        income.setDate(Time::getCurrentDate());
        income.setIntDate(Time::convertStringDateToIntDate(income.getDate()));
    }
    else if(decision == '2')
    {
        string date;
        cout << endl << " >>> AKCEPTOWANY FORMAT DATY PRZYKLAD: 2021-01-01 rrrr-mm-dd ! <<< " << endl << endl;
        cout << "Podaj  date przychodu: ";
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
    else return;

    string description;
    cout << endl << "Podaj opis przychodu: ";
    description = Methods::loadLine();
    income.setDescription(description);

    string amount;
    cout << "Podaj kwote: ";
    cin >> amount;

    income.setAmount(Methods::commaToDotSwap(amount));

    incomesXMLFile.saveIncomeToXMLFile(income);
    incomes.push_back(income);

    sort(incomes.begin(),incomes.end());
}


void IncomesManager::displayIncome(Income income)
{
    cout << endl;
    cout << "DATA:        " <<  income.getDate() << endl;
    cout << "OPIS:         " << income.getDescription() << endl;
    cout << "KWOTA:          " << income.getAmount() << endl;
    cout << "-----------------------------------------" << endl;
    cout << endl;
}


void IncomesManager::displayIncomes(int firstDate,int secondDate)
{
    system("cls");
    periodIncome = 0;
    cout << "-------------LISTA_PRZYCHODOW---------------" << endl;
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
