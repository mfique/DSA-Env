#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Class for Doubly Linked List
class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() { head = nullptr; }

    // Function to insert a new node at the end
    void insert(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            newNode->prev = nullptr;
            head = newNode;
            return;
        }

        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }

        last->next = newNode;
        newNode->prev = last;
    }

    // Function to display the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insert(10);
    dll.insert(20);
    dll.insert(30);
    
    cout << "Doubly Linked List: ";
    dll.display();

    return 0;
}

