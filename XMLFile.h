#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include <string>
#include "Markup.h"
#include "Methods.h"

using namespace std;

class XMLFile
{
    string FILE_ROOT;

public:

    XMLFile(string fileName): FILE_ROOT(fileName) {};
    string getFileRoot();
};





#endif // XMLFILE_H
