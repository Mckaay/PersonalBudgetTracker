#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

using namespace std;

class User
{
    int ID;
    string login;
    string password;

public:
    User(int ID = 1, string login = "admin", string password = "admin")
    {
        this->ID = ID;
        this->login = login;
        this->password = password;
    }
    void setId(int ID);
    void setLogin(string login);
    void setPassword(string password);

    int getId();
    string getLogin();
    string getPassword();



};




#endif
