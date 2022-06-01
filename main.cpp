#include <iostream>
#include <vector>
#include <string>
#include <vector>

#include "UsersXMLFile.h"


using namespace std;

void displayUser(User user)
{
    cout << user.getId() << endl;
    cout << user.getLogin() << endl;
    cout << user.getPassword() << endl;
}


int main()
{
    string fileRoot = "C:\\Users\\progg\\Desktop\\Budget\\PersonalBudgetTracker\\Users.xml";

    UsersXMLFile usersXMLFile(fileRoot);

    vector <User> users = usersXMLFile.loadUserDataFromXMLFileToVector();

    for (auto it1 = users.begin(); it1 != users.end(); it1++)
    {
        displayUser(*it1);
    }

    User user(6,"12345","12345");

    usersXMLFile.saveUserToXMLFile(user);

    users.clear();

    users = usersXMLFile.loadUserDataFromXMLFileToVector();

    cout << endl << endl << endl;

    for (auto it1 = users.begin(); it1 != users.end(); it1++)
    {
        displayUser(*it1);
    }



    return 0;
}
