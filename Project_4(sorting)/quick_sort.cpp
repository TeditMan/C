#include <iostream>

void print_array(int const *array, unsigned n) {
    std::cout << '[' << array[0];
    for (unsigned i = 1; i < n; i++) {
        std::cout << ", "<< array[i];
    }
    std::cout << ']' << std::endl;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void qsort(int *array, unsigned size) {
    if (size < 2) {
        return;
    }
    unsigned left_pointer = 0, right_pointer = size - 2;
    while (left_pointer < right_pointer or (size == 2 and left_pointer == right_pointer and array[0] <= array[1])) {
        while (array[left_pointer] <= array[size - 1] and left_pointer < size - 1) {
            left_pointer++;
        }
        while (array[right_pointer] > array[size - 1] and right_pointer > 0) {
            right_pointer--;
        }
        if (left_pointer < right_pointer) {
            swap(array[left_pointer], array[right_pointer]);
        }
    }
    swap(array[left_pointer], array[size - 1]);
    qsort(array, left_pointer);
    qsort(array + left_pointer + 1, size - left_pointer - 1);
}

int main() {
    int arr[20] = {1, 5, 2, 45, 7, 8, 9, 10, 5, 6, 7,
                   8, 9, 0, 13, 31, 73, 43, 19, 21};
    print_array(arr, 20);

    qsort(arr, 20);
    print_array(arr, 20);
    return 0;
}