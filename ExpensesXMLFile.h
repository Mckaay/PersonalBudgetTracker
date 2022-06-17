#ifndef EXPENSESXMLFILE_H
#define EXPENSESXMLFILE_H

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iomanip>

#include "XMLFile.h"
#include "Expense.h"
#include "Time.h"

class ExpensesXMLFile:public XMLFile
{
    int lastExpenseId;

public:
    ExpensesXMLFile(string fileRoot): XMLFile(fileRoot)
    {
        lastExpenseId = 0;
        CMarkup xml;
        if(!xml.Load(getFileRoot()))
        {
            xml.AddElem( "EXPENSES-LIST");
            xml.Save(getFileRoot());
        }
    };
    void saveExpenseToXMLFile(Expense expense);
    vector <Expense> loadExpensesFromXMLFileToVector(int userId);
    int getLastExpenseId();
    void setLastExpenseId(int lastExpenseId);
};





#endif
