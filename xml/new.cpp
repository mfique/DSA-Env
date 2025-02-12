#include<iostream>
using namespace std;

namespace userDefined {
    int insideNamespace = 100;
    int coutFunc() {
        return insideNamespace;
    }
}

int myGlobal = 50;

int coutFuncGlobal() {
    return myGlobal * myGlobal;
}

int main() {
    int localVar = 20;
    
    cout << "The local variable cout in main is " << localVar << endl;
    cout << "The variable in userDefined namespace is " << userDefined::insideNamespace << endl;
    cout << "The output of cout() in userDefined is " << userDefined::coutFunc() << endl;
    cout << "The value of myGlobal is " << myGlobal << endl;
    cout << "The output of global cout() is " << coutFuncGlobal() << endl;

    return 0;
}

