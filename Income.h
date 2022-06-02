#ifndef INCOME_H
#define INCOME_H

#include <iostream>
#include <string>
#include "Operation.h"


class Income:public Operation
{

public:
    Income(int date, float amount, int id, int userId, string description)
    {
        this->date = date;
        this->amount = amount;
        this->id = id;
        this->userId = userId;
        this->description = description;
    }

};


#endif
