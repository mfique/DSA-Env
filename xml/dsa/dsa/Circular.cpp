#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the end of the list
void insert(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (!head) { // If the list is empty
        head = newNode;
        newNode->next = head; // Point to itself
    } else {
        Node* temp = head;
        while (temp->next != head) { // Traverse to the last node
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head; // Point to the head
    }
}

// Function to display the circular linked list
void display(Node* head) {
    if (!head) return;

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head); // Loop until back to the head
    cout << endl;
}

// Function to delete a node
void deleteNode(Node*& head, int value) {
    if (!head) return;

    Node* temp = head;
    Node* prev = nullptr;

    // Case: Deleting the head node
    if (head->data == value) {
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        delete head;
        head = temp->next;
        return;
    }

    // Traverse to find the node to delete
    do {
        prev = temp;
        temp = temp->next;
    } while (temp != head && temp->data != value);

    if (temp->data == value) {
        prev->next = temp->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);

    cout << "Circular Linked List: ";
    display(head);

    deleteNode(head, 20);
    cout << "After Deletion: ";
    display(head);

    return 0;
}

