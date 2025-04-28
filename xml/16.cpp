#include <iostream>
using namespace std;
int main() {
    // Write C++ code here
double t=50;
int k=55;
int *p=&k;
double *s=&t;
int arr[5]={10,20,30,40,50};
int *pArr=arr;
// cout<<t<<endl;
// cout<<*s<<endl;
// cout<<"size of int point "<<sizeof(p)<<endl;
// cout<<"size of double point "<<sizeof(s)<<endl;
// cout<<"The first element is "<<arr[0]<<endl;
// cout<<"The first element is "<<*pArr<<endl;
// cout<<"The first element si"<<*arr<<endl;
cout<<"Using a pointer"<<endl;
for(int i=0;i<5;i++){
    cout<<"Element at index i="<<i<<" is "<<*(pArr+i)<<endl;
}
for(int i=0;i<5;i++){
    cout<<"Element at index i="<<i<<" is "<<*(arr+i)<<endl;
}
    return 0;
}
