#ifndef USERSXMLFILE_H
#define USERSXMLFILE_H

#include <iostream>
#include <string>
#include <vector>
#include "XMLFile.h"
#include "User.h"

using namespace std;

class UsersXMLFile:public XMLFile
{

public:
    UsersXMLFile(string fileName): XMLFile(fileName)
    {
        CMarkup xml;
        if(!xml.Load(getFileRoot()))
        {
            xml.AddElem( "USER-LIST");
            xml.IntoElem();
            xml.OutOfElem();
            xml.Save(getFileRoot());
        }

    };
    void saveUserToXMLFile(User user);
    vector <User> loadUserDataFromXMLFileToVector();
    void savePasswordChangeToXMLFile(string login,string newPassword);

};




#endif
