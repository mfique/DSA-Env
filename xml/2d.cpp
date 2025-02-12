#include <iostream>
using namespace std;

int main() {
    int marks[3][4] = {
        {80, 75, 76, 75}, 
        {54, 72, 55, 70}, 
        {65, 85, 35, 59}
    };

    // Access specific elements using their indexes
    cout << "Accessing elements using their indexes:" << endl;
    cout << "marks[0][0] = " << marks[0][0] << endl; // 1st student, 1st course
    cout << "marks[0][1] = " << marks[0][1] << endl; // 1st student, 2nd course
    cout << "marks[1][2] = " << marks[1][2] << endl; // 2nd student, 3rd course
    cout << "marks[2][3] = " << marks[2][3] << endl; // 3rd student, 4th course

    return 0;
}

