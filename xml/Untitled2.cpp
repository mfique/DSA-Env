#include<iostream>
using namespace std;
int main(){
	int score[]={52,78,75,68,88,63,75,90,78};
	int k=3;
	int len=7;
	int item=10;
	int j=len-1;
	while(j>=k){
		score[j+1]=score[j];
		j=j-1;
		
		
	}
	score[k]=item;
	for(int l=0;l<=len+1;l++){
		cout<<score[l]<<endl;
	}
		return 0;
	}
