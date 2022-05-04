//
// Created by User on 19.04.2022.
//
#pragma ide diagnostic ignored "misc-no-recursion"
#include <iostream>

void swap(unsigned &a, unsigned &b) {
    unsigned temp = a;
    a = b;
    b = temp;
}

void qsort(unsigned *array, unsigned n) {
    if (n < 2) {
        return;
    }
    unsigned left_pointer = 0, right_pointer = n - 2;
    while (left_pointer < right_pointer or (n == 2 and left_pointer == right_pointer and array[0] <= array[1])) {
        while (array[left_pointer] <= array[n - 1] and left_pointer < n - 1) {
            left_pointer++;
        }
        while (array[right_pointer] > array[n - 1] and right_pointer > 0) {
            right_pointer--;
        }
        if (left_pointer < right_pointer) {
            swap(array[left_pointer], array[right_pointer]);
        }
    }
    swap(array[left_pointer], array[n - 1]);
    qsort(array, left_pointer);
    qsort(array + left_pointer + 1, n - left_pointer - 1);
}

unsigned max_nominal(unsigned number, unsigned nominal) {
    unsigned counter = 0;
    while (counter * nominal <= number) {
        counter++;
    }
    return --counter;
}

unsigned amount_of_variants(unsigned *array_of_nominal, unsigned length_of_array, unsigned number) {
    if (length_of_array == 1) {
        return 1;
    }
    unsigned counter = 0;
    for (unsigned i = 0; i <= max_nominal(number, array_of_nominal[length_of_array - 1]); i++) {
        counter += amount_of_variants(array_of_nominal,length_of_array - 1,
                                      number - i * array_of_nominal[length_of_array - 1]);
    }
    return counter;
}
int main() {
    unsigned array_of_nominal[5] = {50, 25, 10, 5, 1}, n;
    std::cin >> n;
    qsort(array_of_nominal, 5);
    std::cout << amount_of_variants(array_of_nominal, 5, n);
    return 0;
}
