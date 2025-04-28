#include<iostream>
using namespace std;
int main(){
int k=20;
int *ptr=&k;
int *q=ptr;
(*q)++;
cout<<k<<endl;	
return 0;
}
