#include <bits/stdc++.h>
using namespace std;
struct Node {
public:
    int data;
    Node* next;
Node(int data){
this->data=data;
this->next=NULL;
}
};


Node* insertAtHead(Node *head, int data){
         
        Node* n = new Node(data);
        n->data=data;
        n->next = head;
        head = n;
        return head;
}
Node* insertAtPos(Node *head, int i, int data){
      if(i<0){
        return head;
      }
      if(i==0){
        Node* n = new Node(data);
        n->next = head;
        head = n;
        return head;
      }
      Node *temp = head;
      int count = 1;
      while(count<=i-1 && head!=NULL){
        head = head->next;
        count++;
      }
      if(head){
        Node *n = new Node(data);
        n->next = head->next;
        head->next = n;
     
        return temp;
      }
      return temp;
}
void display(Node* n)
{
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
cout<<endl;
}
 // Main
int main()
{
   Node* root = NULL;
    Node* second = NULL;
    Node* third = NULL;
    root = new Node(1);
    second = new Node(2);
    third = new Node(3);
    root->next=second;
    second->next=third;
   Node *head=root;
    cout<<"Initial "<<endl;
    display(head);
    head=insertAtPos(head,2,250);
    display(head);
    cout<<"After adding at 2"<<endl;
     head=insertAtPos(head,4,200);
    display(head);
    cout<<"After adding at 4"<<endl;
     head=insertAtPos(head,0,150);
    display(head);
    cout<<"After adding at 0"<<endl;
    head=insertAtPos(head,6,550);
    display(head);
    cout<<"After adding at 6"<<endl;
    return 0;
}

