#ifndef INCOMESMANAGER_H
#define INCOMESMANAGER_H

#include "IncomesXMLFile.h"
#include "Methods.h"

class IncomesManager
{
    const int LOGGED_IN_USER_ID;
    vector <Income> incomes;
    IncomesXMLFile incomesXMLFile;
    double periodIncome;

    void displayIncome(Income income);

public:
    IncomesManager(string fileRoot,int loggedInUserId): incomesXMLFile(fileRoot), LOGGED_IN_USER_ID(loggedInUserId)
    {
        periodIncome = 0;
        incomes = incomesXMLFile.loadIncomesFromXMLFileToVector(LOGGED_IN_USER_ID);
        sort(incomes.begin(),incomes.end());
    };
    void addIncome();
    void displayIncomes(int firstDate,int secondDate);
    double getPeriodIncome();
};


#endif // INCOMESMANAGER_H
