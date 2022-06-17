#ifndef INCOMESXMLFILE_H
#define INCOMESXMLFILE_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

#include "Income.h"
#include "Time.h"
#include "XMLFile.h"

class IncomesXMLFile:public XMLFile
{
    int lastIncomeId;

public:
    IncomesXMLFile(string fileRoot): XMLFile(fileRoot)
    {
        lastIncomeId = 0;
        CMarkup xml;
        if(!xml.Load(getFileRoot()))
        {
            xml.AddElem( "INCOMES-LIST");
            xml.Save(getFileRoot());
        }
    };
    void saveIncomeToXMLFile(Income income);
    vector <Income> loadIncomesFromXMLFileToVector(int userId);
    int getLastIncomeId();
    void setLastIncomeId(int lastIncomeId);
};

#endif
