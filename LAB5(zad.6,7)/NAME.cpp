#include "NAME.h"


Name::Name(const string& aName) : objectName(aName) {
   // cout << "Wywolanie konstruktora Name" << endl; 
}

Name::Name() : Name("Domyslna nazwa") {
   // cout << "Wywolanie konstruktora domyslnego Name " << endl;
}

Name::~Name() {
   // cout << "Wywolanie destruktora Name" << endl;
}