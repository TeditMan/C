#include <iostream>

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void qsort(int *array, int n) {
    int l = 0, r = n - 1, k = n / 2, rep = array[k];
    if (n < 2) {
        return;
    }
    do {
        while (array[l] < rep) {
            l++;
        }
        while (array[r] > rep) {
            r--;
        }
        if (l < k and r > k) {
            swap(array[l], array[r]);
        }
        else if (l == k and r > k) {
            swap(array[k], array[r]);
            swap(array[r], array[k + 1]);
            k += 1;
            l += 1;
        }
        else if (l < k and r == k) {
            swap(array[k], array[l]);
            swap(array[l], array[k - 1]);
            k -= 1;
            r -= 1;
        }
    } while (l < r);
    qsort(array, k);
    qsort(array + k + 1, n - k - 1);
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
    for (int i : arr) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
    qsort(arr, 20);
    for (int i : arr) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
    heap_sort(arr, 20);
    for (int i : arr) {
        std::cout << i << ' ';
    }
    return 0;
}