#include<iostream>
using namespace std;
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    for(int i=0; i< 9-1; i++){
        for(int j=0; j< 9-1;j++){
        	cout<< i <<""<< j << "" << i*j << endl;
            if(arr[j]> arr[j+1]){
                int temp = arr[j];
                arr[j]= arr[j+1];
                arr[j+1]= temp;
            }
        }
    }
    for(int k=0; k<9; k++){
        cout << arr[k]<< " ";
    }
    cout << endl;
    return 0;
}







