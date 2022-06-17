#include "Operation.h"

string Operation::getDate()
{
    return this->strDate;
}

int Operation::getIntDate()
{
    return this->date;
}

double Operation::getAmount()
{
    return this->amount;
}
int Operation::getId()
{
    return this->id;
}
int Operation::getUserId()
{
    return this->userId;
}
string Operation::getDescription()
{
    return this->description;
}

void Operation::setDate(string date)
{
    this->strDate = date;
}

void Operation::setIntDate(int date)
{
    this->date = date;
}

void Operation::setAmount(double amount)
{
    this->amount = amount;
}

void Operation::setId(int id)
{
    this->id = id;
}

void Operation::setUserId(int userId)
{
    this->userId = userId;
}

void Operation::setDescription(string description)
{
    this->description = description;
}
