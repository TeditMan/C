#include <iostream>
#include <random>

int fact(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return n * fact(n - 1);
    }
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void select_sort(int array[], int n) {
    int max_idx = 0;
    for (int i = 0; i < n; i++) {
        max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[max_idx]) {
                max_idx = j;
            }
        }
        swap(array[i], array[max_idx]);
    }
}

void qsort(int (&array)[15], int n) {
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
            swap(array[k], array[k + 1]);
            swap(array[k], array[r]);
            k += 1;
            l += 1;
        }
        else if (l < k and r == k) {
            swap(array[k], array[k - 1]);
            swap(array[k], array[l]);
            k -= 1;
            r -= 1;
        }
    } while (l < r);
    qsort(array, l - 1);
    // qsort(array, n - l - 1);
}

void heap_sort(int (&array)[], int n) {

}

int main() {
    int arr[15] = {1, 5, 2, 45, 7, 8, 9, 10, 5, 6, 7, 8, 9, 0, 13};
    qsort(arr, 15);
    for (int i : arr) {
        std::cout << i << ' ';
    }
    return 0;
}

