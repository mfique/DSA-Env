#include <iostream>

int power(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

int main() {
    int base = 5;
    int exponent = 3;
    std::cout << power(base, exponent) << std::endl;
    return 0;
}

