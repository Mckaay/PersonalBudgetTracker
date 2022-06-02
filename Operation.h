#ifndef OPERATION_H
#define OPERATION_H

#include <iostream>
#include <string>

using namespace std;

class Operation
{
protected:
    int date;
    float amount;
    int id;
    int userId;
    string description;

public:
    int getDate();
    float getAmount();
    int getId();
    int getUserId();
    string getDescription();

    void setDate(int date);
    void setAmount(float amount);
    void setId(int id);
    void setUserId(int userId);
    void setDescription(string description);

};



#endif
