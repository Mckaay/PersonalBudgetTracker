#include "ExpensesXMLFile.h"

void ExpensesXMLFile::saveExpenseToXMLFile(Expense expense)
{
    CMarkup xml;
    xml.Load( getFileRoot() );
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("EXPENSE");
    xml.IntoElem();
    xml.AddElem( "USER_ID", expense.getUserId());
    xml.AddElem( "EXPENSE_ID", expense.getId());
    xml.AddElem( "DATE", expense.getDate());
    xml.AddElem( "DESCRIPTION", expense.getDescription());
    xml.AddElem( "AMOUNT", expense.getAmount());
    xml.OutOfElem();

    xml.Save( getFileRoot() );
}
vector <Expense> ExpensesXMLFile::loadExpensesFromXMLFileToVector(int userId)
{
    vector <Expense> expenses;

    CMarkup xml;
    xml.Load( getFileRoot() );
    xml.FindElem();
    xml.IntoElem();

    while(xml.FindElem("EXPENSE"))
    {
        Expense expense;
        xml.IntoElem();
        xml.FindElem("USER_ID");
        if(stoi(xml.GetData()) == userId)
        {
            expense.setUserId(stoi(xml.GetData()));
            xml.FindElem("EXPENSE_ID");
            expense.setId(stoi(xml.GetData()));
            lastExpenseId = expense.getId();
            xml.FindElem("DATE");
            expense.setDate(xml.GetData());
            expense.setIntDate(Time::convertStringDateToIntDate(xml.GetData()));
            xml.FindElem("DESCRIPTION");
            expense.setDescription(xml.GetData());
            xml.FindElem("AMOUNT");
            expense.setAmount(stoi(xml.GetData()));
            expenses.push_back(expense);
        }
        xml.OutOfElem();
    }
    return expenses;
}

int ExpensesXMLFile::getLastExpenseId()
{
    return this->lastExpenseId;
}
