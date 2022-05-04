//
// Created by User on 22.04.2022.
//
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

void make_tree_down_from_point(int *array, unsigned size, unsigned index) {
    unsigned left_child = 2 * index + 1, right_child = 2 * index + 2, index_of_least;
    if (left_child >= size) {
        left_child = index;
    }
    if (right_child >= size) {
        right_child = index;
    }
    if (array[left_child] <= array[right_child] and array[left_child < array[index]]) {
        index_of_least = left_child;
    }
    else if (array[right_child] < array[left_child] and array[right_child] < array[index]) {
        index_of_least = right_child;
    }
    else index_of_least = index;
    if (index != index_of_least) {
        swap(array[index], array[index_of_least]);
        make_tree_down_from_point(array, size, index_of_least);
    }
}

void heapSort(int *array, unsigned size) {
    /*
    for (unsigned i = size / 2 - 1; i > 0; i--) {
        //make_tree_down_from_point(array, size, i);
    }
     */
    for (unsigned i = size - 1; i >= 0; i--) {
        //swap(array[0], array[i]);
        make_tree_down_from_point(array, i, 0);
    }
}

int main() {
    int arr[20] = {1, 5, 2, 45, 7, 8, 9, 10, 5, 6, 7,
                   8, 9, 0, 13, 31, 73, 43, 19, 21};
    print_array(arr, 20);

    heapSort(arr, 20);
    print_array(arr, 20);
    return 0;
}