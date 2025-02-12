#include<iostream>
using namespace std;

class Node {
   public:
     int data;
     Node *next;

     Node(int data){
       this->data = data;
       next = NULL;
     }
};

void print(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* UserData(){
   int data;
   cin >> data;
   Node *head = NULL;
   Node *tail = NULL;
   while(data != -1){
    // Creating the linked list
    Node *n = new Node(data);
    
    // Insert at head
    if(head == NULL){
        head = n;
        tail = n;
    } else {
        n->next = head; // Inserting at head
        head = n;
    }
    cin >> data;
   }
   return head;
}

int main(){
   Node *head = UserData();
   print(head);
   return 0;
}

