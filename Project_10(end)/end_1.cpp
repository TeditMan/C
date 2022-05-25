#include <iostream>
using namespace std;

void circle(int *array, int start_number, int start_point, int array_size) {
    int i = start_point, j = start_point, counter = start_number;
    while (j < array_size - start_point) {
        array[array_size * i + j] = counter;
        j++;
        counter++;
    }
    counter--;
    j--;
    while (i < array_size - start_point) {
        array[array_size * i + j] = counter;
        i++;
        counter++;
    }
    i--;
    counter--;
    while (j >= start_point) {
        array[array_size * i + j] = counter;
        j--;
        counter++;
    }
    j++;
    counter--;
    while (i > start_point) {
        array[array_size * i + j] = counter;
        i--;
        counter++;
    }
}

void fill(int *array, int array_size) {
    int start_number = 1, start_point = 0;
    while (start_point < (array_size + 1) / 2) {
        circle(array, start_number, start_point, array_size);
        start_number += ((array_size - 2 * start_point - 1) * 4);
        start_point++;
    }
}

void print_array(int *array, int size) {
    int i = 0, j = 0;
    while (i < size) {
        while (j < size) {
            cout << array[size * i + j] << ' ';
            if (array[size * i + j] < 10) {
                cout << "  ";
            }
            else if (array[size * i + j] < 100) {
                cout << ' ';
            }
            j++;
        }
        j = 0;
        i++;
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    auto *array = new int[n * n];
    fill(array, n);
    print_array(array, n);
    delete[] array;
    return 0;
}