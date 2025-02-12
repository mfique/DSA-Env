#include<iostream>
using namespace std;
//int queue[100], n=100, front=-1, rear=-1;
	struct Queue{
	int front;
	int rear;
	int capacity;
	int *queue;
	int size;
	Queue(int cap){
	capacity=cap;
	front=rear=-1;
	size=0;
	queue= new int[capacity];
	}
//Adding an element in the queue
void enqueue(int val){
if(isFull()){
cout<<"The queue is full"<<endl;
}
else
{
if(front==-1){
front=0;
}
rear++;
queue[rear]=val;
size++;
}
}
//Remove/delete an element in the queue
void dequeue(){
if(isEmpty()){
cout<<"The queue is empty"<<endl;
}
else{
cout<<"The removed front is"<<queue[front]<<endl;
front++;
size--;
}
}
//Getting the front element or  front()
int peek(){
if(isEmpty()){
//cout<<cout<<"The queue is empty"<<endl;
return 0;
}
else{

return  queue[front];
}
}
int count(){
return size;
}
bool isFull(){
return size==capacity;
}
bool isEmpty(){
return size==0;
}
void display(){
if(isEmpty()){
cout<<"The queue is empty"<<endl;
}
else{
for (int i=front; i<=rear;i++){
cout<<"The element at front= "<<i<<" is "<<queue[i]<<endl;
}}}
};

int main(){
Queue q(5);
cout<<"Adding elements"<<endl;
q.enqueue(10);
q.enqueue(20);
q.enqueue(30);
q.enqueue(40);
q.enqueue(50);
q.enqueue(60);
q.enqueue(70);
cout<<"End of addition of elements"<<endl;
q.display();
q.dequeue();
q.dequeue();
q.display();
cout<<"The front element is"<<q.peek()<<endl;
cout<<"The number of elements in the queue is "<<q.count()<<endl;
return 0;
}
