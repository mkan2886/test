#pragma once
#include <string>
#include <iostream>

using namespace std; 

class Name {
protected:
    string objectName;

public:
    Name(const string& aName);
    Name();
    ~Name();
};