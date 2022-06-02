#include "Operation.h"

int Operation::getDate()
{
    return this->date;
}
float Operation::getAmount()
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

void Operation::setDate(int date)
{
    this->date = date;
}

void Operation::setAmount(float amount)
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
