#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include <string>
#include "Operation.h"


class Expense:public Operation
{

public:
    Expense(int date, float amount, int id, int userId, string description)
    {
        this->date = date;
        this->amount = amount;
        this->id = id;
        this->userId = userId;
        this->description = description;
    }

};


#endif
