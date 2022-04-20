#include <string>
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

int main() {
    unsigned s, N;
    std::cin >> s >> N;
    auto *array_of_users = new unsigned[N];
    for (int i = 0; i < N; i++) {
        std::cin >> array_of_users[i];
    }
    qsort(array_of_users, N);
    unsigned counter = 0;

    unsigned i = -1;
    while (counter <= s) {
        counter += array_of_users[i];
        i += 1;
    }
    std::cout << i;
    return 0;
}