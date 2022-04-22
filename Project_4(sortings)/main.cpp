#include <iostream>

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void print_array(int const *array, unsigned n) {
    std::cout << '[' << array[0];
    for (unsigned i = 1; i < n; i++) {
        std::cout << ", "<< array[i];
    }
    std::cout << ']' << std::endl;
}

void qsort(int *array, unsigned n) {
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

void heap_sort(int *array, int n) {
    if (n < 2) {
        return;
    }
    if (n % 2 == 0) {
        if (array[n - 1] > array[(n - 2) / 2]) {
            swap(array[n - 1], array[(n - 2) / 2]);
        }
    }
    else {
        if (array[n - 1] < array[n - 2] and
            array[n - 2] > array[(n - 2) / 2]) {
            swap(array[n - 2], array[(n - 2 ) / 2]);
        }
        else if (array[n - 1] > array[n - 2] and
                 array[n - 1] > array[(n - 2) / 2]) {
            swap(array[n - 1], array[(n - 2) / 2]);
        }
    }
    for (int i = (n - 2) / 2 - 1; i >= 0; i--) {
        if (array[2 * i + 1] < array[2 * i + 2] and
            array[2 * i + 2] > array[i]) {
            swap(array[2 * i + 2], array[i]);
        }
        else if (array[2 * i + 1] >= array[2 * i + 2] and
                 array[2 * i + 1] >= array[i]) {
            swap(array[2 * i + 1], array[i]);
        }
    }
    for (int i = 0; i < (n - 2)/ 2; i++) {
        if (array[2 * i + 1] < array[2 * i + 2] and
            array[2 * i + 2] > array[i]) {
            swap(array[2 * i + 2], array[i]);
        }
        else if (array[2 * i + 1] >= array[2 * i + 2] and
                 array[2 * i + 1] >= array[i]) {
            swap(array[2 * i + 1], array[i]);
        }
    }
    if (n % 2 == 0) {
        if (array[n - 1] > array[(n - 2) / 2]) {
            swap(array[n - 1], array[(n - 2) / 2]);
        }
    }
    else {
        if (array[n - 1] < array[n - 2] and
            array[n - 2] > array[(n - 2) / 2]) {
            swap(array[n - 2], array[(n - 2 ) / 2]);
        }
        else if (array[n - 1] > array[n - 2] and
                 array[n - 1] > array[(n - 2) / 2]) {
            swap(array[n - 1], array[(n - 2) / 2]);
        }
    }
    swap(array[0], array[n - 1]);
    heap_sort(array, n - 1);
}

int main() {
    int arr[20] = {1, 5, 2, 45, 7, 8, 9, 10, 5, 6, 7,
                   8, 9, 0, 13, 31, 73, 43, 19, 21};
    print_array(arr, 20);

    qsort(arr, 20);
    print_array(arr, 20);

    heap_sort(arr, 20);
    print_array(arr, 20);
    return 0;
}