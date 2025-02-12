#include<iostream>
using namespace std;
class Rectangle{
	private:
		int width;
		int length;
		
		public:
			int area(){
				return width*length;
		
			}
			void setValues(int w,int l){
				width=w;
				length=l;
			}
			Rectangle(){
			}
			Rectangle(int w,int l){
				width=w;
				length=l;
			}
};
int main(){
	Rectangle recta;
	recta.setValues(20,10);
	cout<<"area is"<<recta.area()<<endl;
	return 0;
}

