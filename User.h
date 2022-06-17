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
    string name;
    string surname;

public:
    User(int ID = 1, string login = "admin", string password = "admin",string name = "Jan", string surname = "Kowalski")
    {
        this->ID = ID;
        this->login = login;
        this->password = password;
        this->name = name;
        this->surname = surname;
    }
    void setId(int ID);
    void setLogin(string login);
    void setPassword(string password);
    void setName(string name);
    void setSurname(string surname);

    int getId();
    string getLogin();
    string getPassword();
    string getName();
    string getSurname();
};




#endif
