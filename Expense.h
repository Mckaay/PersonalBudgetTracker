#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include <string>
#include "Operation.h"
#include "Time.h"


class Expense:public Operation
{

public:
    Expense(string date = "2000-01-01", float amount = 1, int id = 0, int userId = 0, string description = "default")
    {
        this->strDate = date;
        this->date = Time::convertStringDateToIntDate(strDate);
        this->amount = amount;
        this->id = id;
        this->userId = userId;
        this->description = description;
    }

    bool operator < (const Expense& expense) const
    {
        return (date < expense.date);
    }

};


#endif
