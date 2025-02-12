#include<iostream>
using namespace std;
class Student{
	public:
		int code;
		string name;
		string school;
		int age;
		Student *next;
		Student(){}
		Student(int c,string nm,int a,string sch){
			code=c;
			name=nm;
			age=a;
			school=sch;
			next=NULL;
		}
		
};
void display(Student *head){
			while(head!=NULL){
				cout<<head->code<<" "<<head->age<<" years "<<head->name<<" "<<head->school<<"->"<<endl;
				head=head->next;
				
			}
			cout<<"NULL";
		}
		int main(){
			Student *s1=new Student(101,"Divine",12,"RCA");
			Student *s2=new Student(102,"Divin",15,"RCA");
			Student *s3=new Student(113,"Dan",17,"RCA");
			Student *s4=new Student(105,"Mike",19,"RCA");
			Student s5(110,"Gloria",20,"RCA");
			
			s1->next=s2;
			s2->next=s3;
			s3->next=s4;
			s4->next=&s5;
			display(s1);
			return 0;
		}
