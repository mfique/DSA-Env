#include<iostream>
using namespace std;

namespace mydata {
    int amount = 1000;
    int power() {
        return amount * amount;
    }
}

int amount = 5000;

int main() {
    int amount = 3000;

    cout << "The local amount is " << amount << endl;
    cout << "The Global amount is " << ::amount << endl;
    cout << "The amount in mydata is " << mydata::amount << endl;
    cout << "The value of power is " << mydata::power() << endl;

    return 0;
}

