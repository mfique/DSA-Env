#include <iostream>
using namespace std;

class Rectangle {
private:
    int width;
    int length;

public:
    Rectangle(int w, int l) {
        width = w;
        length = l;
    }

    int area() {
        return width * length;
    }

    void setValue(int w, int l) {
        width = w;
        length = l;
    }

    void display() {
        cout << "Width: " << width << ", Length: " << length << ", Area: " << area() << endl;
    }
};

int main() {
    Rectangle rect(5, 10);
    rect.display();

    rect.setValue(7, 14);
    rect.display();

    return 0;
}

