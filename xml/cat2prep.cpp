#include <iostream>
using namespace std;
int main()
{
int a = 15;
int b = 20;
int *c = &b;
*c = 15;
 cout << a << " " << b << endl;

    return 0;
}
