#include<iostream>
using namespace std;

struct Student {
    int id;
    std::string name;
    int age;
    Student* next;
};

class StudentPriorityQueue {
private:
    Student* head;

public:
    StudentPriorityQueue() : head(NULL) {}
    
    ~StudentPriorityQueue() {
        while (head) {
            dequeue();
        }
    }

    void enqueue(int id, std::string name, int age) {
        Student* newStudent = new Student{id, name, age, NULL};
        if (!head || age > head->age) { // Higher age has higher priority
            newStudent->next = head;
            head = newStudent;
        } else {
            Student* temp = head;
            while (temp->next && temp->next->age >= age) {
                temp = temp->next;
            }
            newStudent->next = temp->next;
            temp->next = newStudent;
        }
        cout << "Enqueued: " << name << " (Age: " << age << ")" << endl;
    }

    void dequeue() {
        if (!head) {
            std::cout << "Queue is empty! Cannot dequeue." << std::endl;
            return;
        }
        std::cout << "Dequeued: " << head->name << " (Age: " << head->age << ")" << std::endl;
        Student* temp = head;
        head = head->next;
        delete temp;
    }

    void display() {
        if (!head) {
            std::cout << "Queue is empty!" << std::endl;
            return;
        }
        std::cout << "Priority Queue (Higher Age -> Higher Priority):" << std::endl;
        Student* temp = head;
        while (temp) {
            std::cout << "ID: " << temp->id << ", Name: " << temp->name << ", Age: " << temp->age << std::endl;
            temp = temp->next;
        }
    }
};

int main() {    
    StudentPriorityQueue sq;
    sq.enqueue(101, "Fique", 25);
    sq.enqueue(102, "Paci", 30);
    sq.enqueue(103, "Hatuma", 22);
    sq.display();
    
    sq.dequeue();
    sq.display();
    
    return 0;
}

