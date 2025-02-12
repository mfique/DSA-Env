#include<iostream>
int difference(){
	int arr[10]={5,7,12,14,15,9,8,2,3,10};
		int sumEven=0;
		int sumOdd=0;
	for(int i=0;i<sizeof(arr)/sizeof(int);i++){
		if(arr[i]%2==0)
			sumEven+=arr[i];
		
		else
		sumOdd+=arr[i];
	}
	return sumOdd-sumEven;
}
template <typename T>
T addition(T a, T b){
	return a+b;	
}
template <typename T>	
T addition(T a, T b,T c){
		return a+b+c;	
	}
int main(){
	using namespace std;
	int result=difference();
	cout<<"the result is:"<<result<<endl;
	
int sum=addition<int>(4,5);
cout<<"sum:"<<sum<<endl;
double sumDouble=addition<double>(4.5,6.4);
cout<<"sum:"<<sumDouble<<endl;
	return 0;
}
