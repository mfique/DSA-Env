#include<iostream>
using namespace std;

template <typename T>
class Node {
    public:
        T data;
        Node *next;
        Node() {
        }
        Node(T d) {
            data = d;
            next = NULL;
        }

        void display(Node<T> *head) {
            while (head != NULL) {
                cout << head->data << " -> ";
                head = head->next;
            }
            cout << "NULL" << endl;
        }
};

int main() {
    Node<int> *n1 = new Node<int>();
    Node<int> *n2 = new Node<int>();
    Node<int> *n3 = new Node<int>();
    Node<int> *n4 = new Node<int>(40);

    n1->data = 10;
    n1->next = n2;
    n2->data = 20;
    n2->next = n3;
    n3->data = 30;
    n3->next = n4;
    n4->data = 40;
    n4->next = NULL;

    cout << "First node data: " << n1->data << endl;
    n1->display(n1);

    return 0;
}

