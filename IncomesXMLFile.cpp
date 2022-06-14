#include "IncomesXMLFile.h"

void IncomesXMLFile::saveIncomeToXMLFile(Income income)
{
    CMarkup xml;
    xml.Load( getFileRoot() );
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("INCOME");
    xml.IntoElem();
    xml.AddElem( "USER_ID", income.getUserId());
    xml.AddElem( "INCOME_ID", income.getId());
    xml.AddElem( "DATE", income.getDate());
    xml.AddElem( "DESCRIPTION", income.getDescription());
    xml.AddElem( "AMOUNT", income.getAmount());
    xml.OutOfElem();

    xml.Save(getFileRoot());
}

vector <Income> IncomesXMLFile::loadIncomesFromXMLFileToVector(int userId)
{
    vector <Income> incomes;

    CMarkup xml;
    xml.Load( getFileRoot() );
    xml.FindElem();
    xml.IntoElem();

    while(xml.FindElem("INCOME"))
    {
        Income income;
        xml.IntoElem();
        xml.FindElem("USER_ID");
        if(stoi(xml.GetData()) == userId)
        {
            income.setUserId(stoi(xml.GetData()));
            xml.FindElem("INCOME_ID");
            income.setId(stoi(xml.GetData()));
            xml.FindElem("DATE");
            income.setDate(xml.GetData());
            income.setIntDate(Time::convertStringDateToIntDate(xml.GetData()));
            xml.FindElem("DESCRIPTION");
            income.setDescription(xml.GetData());
            xml.FindElem("AMOUNT");
            income.setAmount(stoi(xml.GetData()));
            incomes.push_back(income);
        }
        xml.FindElem("INCOME_ID");
        lastIncomeId = stoi(xml.GetData());
        cout << "TUTAJ: " << lastIncomeId << endl;
        xml.OutOfElem();
    }
    return incomes;
}

int IncomesXMLFile::getLastIncomeId()
{
    return this->lastIncomeId;
}
