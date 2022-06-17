#include "IncomesXMLFile.h"

void IncomesXMLFile::saveIncomeToXMLFile(Income income)
{
    CMarkup xml;
    xml.Load( getFileRoot() );
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("INCOME");
    xml.IntoElem();
    xml.AddElem( "INCOME_ID", income.getId());
    xml.AddElem( "USER_ID", income.getUserId());
    xml.AddElem( "DATE", income.getDate());
    xml.AddElem( "DESCRIPTION", income.getDescription());
    xml.AddElem( "AMOUNT", Methods::doubleToStringWithPrecision(income.getAmount()));
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
        xml.FindElem("INCOME_ID");
        income.setId(stoi(xml.GetData()));
        lastIncomeId = income.getId();
        xml.FindElem("USER_ID");
        income.setUserId(stoi(xml.GetData()));
        xml.FindElem("DATE");
        income.setDate(xml.GetData());
        income.setIntDate(Time::convertStringDateToIntDate(xml.GetData()));
        xml.FindElem("DESCRIPTION");
        income.setDescription(xml.GetData());
        xml.FindElem("AMOUNT");
        income.setAmount(stod(xml.GetData()));
        xml.OutOfElem();

        if(userId == income.getUserId())
        {
            incomes.push_back(income);
        }
    }
    return incomes;
}

int IncomesXMLFile::getLastIncomeId()
{
    return this->lastIncomeId;
}

void IncomesXMLFile::setLastIncomeId(int lastIncomeId)
{
    this->lastIncomeId = lastIncomeId;
}
