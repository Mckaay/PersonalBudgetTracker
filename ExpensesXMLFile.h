#ifndef EXPENSESXMLFILE_H
#define EXPENSESXMLFILE_H

#include <iostream>
#include <vector>
#include <string>

#include "XMLFile.h"
#include "Expense.h"

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
            xml.IntoElem();
            xml.OutOfElem();
            xml.Save(getFileRoot());
        }
    };
    void saveExpenseToXMLFile(Expense expense);
    vector <Expense> loadExpensesFromXMLFileToVector(int userId);
    int getLastExpenseId();
};





#endif
