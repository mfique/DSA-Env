#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

Node* deleteFirst(Node* head) {
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* deleteLast(Node* head) {
    if (!head) return NULL;
    if (!head->next) {
        delete head;
        return NULL;
    }
    Node* current = head;
    while (current->next && current->next->next) {
        current = current->next;
    }
    delete current->next;
    current->next = NULL;
    return head;
}

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node *head = new Node(50);
    Node *first = new Node(10);
    Node *second = new Node(35);
    Node *third = new Node(40);
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = NULL;

    head = deleteFirst(head); // Deleting first node
    printList(head);

    head = deleteLast(head); // Deleting last node
    printList(head);

    head = reverse(head); // Reversing the list
    printList(head);

    return 0;
}
