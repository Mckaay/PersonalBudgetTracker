#include "User.h"

void User::setId(int ID)
{
    this->ID = ID;
}
void User::setLogin(string login)
{
    this->login = login;
}
void User::setPassword(string password)
{
    this->password = password;
}

int User::getId()
{
    return this->ID;
}
string User::getLogin()
{
    return this->login;
}
string User::getPassword()
{
    return this->password;
}
