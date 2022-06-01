#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <windows.h>

#include "UsersXMLFile.h"

using namespace std;

class UserManager
{
    int loggedInUserId;
    vector <User> users;
    UsersXMLFile usersXMLFile;

    bool checkIfUserAlreadyExists(string checkedUserLogin);
    int getNewUserId();

public:

    UserManager(string fileRoot): usersXMLFile(fileRoot)
    {
        loggedInUserId = 0;
        users = usersXMLFile.loadUserDataFromXMLFileToVector();
    };
    int getLoggedinUserId();
    void registration();
    void displayUsers();
};


#endif












