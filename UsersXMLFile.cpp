#include "UsersXMLFile.h"

void UsersXMLFile::saveUserToXMLFile(User user)
{
    CMarkup xml;
    xml.Load(getFileRoot());
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("USER");
    xml.IntoElem();
    xml.AddElem( "USER_ID", user.getId());
    xml.AddElem( "USERNAME", user.getLogin());
    xml.AddElem( "PASSWORD", user.getPassword() );
    xml.OutOfElem();

    xml.Save( getFileRoot() );
}

vector <User> UsersXMLFile::loadUserDataFromXMLFileToVector()
{
    vector <User> users;

    CMarkup xml;
    xml.Load(getFileRoot());
    xml.FindElem();
    xml.IntoElem();

    while(xml.FindElem("USER"))
    {
        User user;
        xml.IntoElem();
        xml.FindElem("USER_ID");
        user.setId(stoi(xml.GetData()));
        xml.FindElem("USERNAME");
        user.setLogin(xml.GetData());
        xml.FindElem("PASSWORD");
        user.setPassword(xml.GetData());
        xml.OutOfElem();

        users.push_back(user);
    }
    return users;
}
