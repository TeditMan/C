#include <iostream>

// 3 types of memory

// automatic

// static существуют во время всей жизни программы, память выделяется только один раз, как глобальная переменная

// heap можно динамически выделить куски памяти

// Указатели.

void foo() {
    static int s_a = 0;
    s_a++;
    int a = 0;
    a++;
    std::cout << s_a << ' ' << a << '\n';
}
int main() {
    /*
    for (int i = 0; i < 10; i++) {
        foo();
    }
    */
    int a = 0;
    int *ptr_a, *ptr_b;
    std::cout << &a << " - адрес а в памяти в 16-тиричной системе";
    // heap
    int *d_a = new int(5);
    delete d_a;
    int n;
    std::cin >> n;

    int field[n]; // error

    int *d_array = new int[n];

    delete []d_array;

    // вызов по адресу
    int val_a = *ptr_a;
    // int array[10] -> array + k;
    return 0;
}