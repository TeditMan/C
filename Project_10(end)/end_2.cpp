#include <iostream>
enum type {first, second, third};

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    type b = first;
    int k = 4;
    int &f = k;
    std::cout << sizeof(b);
    for (unsigned i = 0, j = 0; i < 4; i++, j--) {
        int c = 2;
        c++;
    }
    return 0;
}