#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    
    // Constructor to initialize the node with data
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Singly Linked List class
class SinglyLinkedList {
private:
    Node* head;
    
public:
    SinglyLinkedList() {
        head = nullptr;
    }
    
    // Add a new node at the end of the list
    void append(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    // Display the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    
    // Destructor to free memory
    ~SinglyLinkedList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    SinglyLinkedList list;
    list.append(10);
    list.append(20);
    list.append(30);
    
    cout << "Singly Linked List: ";
    list.display();
    
    return 0;
}

