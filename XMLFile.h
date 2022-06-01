#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include <string>
#include "Markup.h"

using namespace std;

class XMLFile
{
    string FILE_ROOT;

public:

    XMLFile(string fileName): FILE_ROOT(fileName) {};
    string getFileRoot();
};





#endif // XMLFILE_H
