#include<iostream>

using namespace std;

struct Queue{
    int front, rear,n;
    int *queue;

    Queue(int c){
        front=rear=-1;
        n=c;
        queue= new int(n);
    }
    void enqueue(){
    int val;
    if(rear== n-1){
        cout<<"Queue overflow/ Full"<<endl;
    }else{
        if(front==-1){
            front =0;
            cout<<"Insert the element in the queue: "<<endl;
            cin>>val;
            rear++;
            queue[rear]= val;
        }
    };
}
void dequeue(){
    if(front == -1 || front > rear){
        cout<<"Queue underflow/ Empty"<<endl;
        return ;
    }
    cout<<"Element deleted from queue is: "<< queue[front]<<endl;
    front++;
}

void display(){
    if(front == -1){
        cout<<"Queue is empty: "<<endl;
    }else{
        cout<<"Queue elements are: ";
        for(int i=front; i<=rear;i++){
            cout<<queue[i]<<" ";
            cout<<endl;
        }
    }
}
void readFront(){
    if(front == -1){
        cout<<"Queue underflow "<<endl;
        return;
    }
    cout<<"Element at front is: "<<queue[front]<<endl;

}
};



int main(){
    int ch;
    Queue q(5);

    cout<<"1. Insert element to queue "<<endl;
    cout<<"2. Delete element from queue "<<endl;
    cout<<"3. Display all the elements of the queue "<<endl;
    cout<<"4. Read element from the queue"<<endl;
    cout<<"5. while "<<endl;

    do{
        cout<<"Enter you choice: "<<endl;
        cin>>ch;
        switch (ch)
        {
        case 1:
            q.enqueue();
            break;
        case 2:
            q.dequeue();
            break;    
        case 3:
            q.display();
            break;
        case 4:
            q.readFront();
            break;  
        case 5:
            cout<<"Exited the queue "<<endl;
            break;      
        default:
            cout<<"Invalid Operation!"<<endl;
            break;
        }
    }while(ch>0 && ch<5);
    return 0;
    
}

