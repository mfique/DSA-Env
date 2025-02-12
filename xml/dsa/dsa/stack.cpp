#include<iostream>
using namespace std;

struct Stack {
    int *arr;
    int capacity;
    int nextIndex;

    Stack(int cap) {
        capacity = cap;
        arr = new int[capacity];
        nextIndex = 0;
    }

    void push(int val) {
        if (isFull()) {
            cout << "Stack overflow" << endl;
        } else {
            arr[nextIndex] = val;
            nextIndex++;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
        } else {
            nextIndex--;
        }
    }

    bool isEmpty() {
        return nextIndex == 0;  // Corrected the return condition
    }

    bool isFull() {
        return nextIndex == capacity;  // Corrected function name
    }

    int peek() {
        if (isEmpty()) {
            return -1;  // Return -1 if stack is empty
        }
        return arr[nextIndex - 1];
    }

    void display() {
        for (int i = 0; i < nextIndex; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack myStack(5);  // Added missing semicolon
    cout << "Start adding elements" << endl;
    
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);
    myStack.push(60);  // This will show stack overflow
    
    myStack.display();
    cout << "The top element in my stack: " << myStack.peek() << endl;
    
    myStack.pop();
    myStack.pop();
    
    myStack.display();
    cout << "The top element in my stack: " << myStack.peek() << endl;
    
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();  // This will show stack underflow
    
    return 0;
}
