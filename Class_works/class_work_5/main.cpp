#include <string>
#include <iostream>
#include "C:\Users\User\CLionProjects\C\Project_5(tasks with pointers and structs)\task_1(single list)\SingleList.h"

struct Pointer{
    unsigned coordinate = 0;
    List *available_stations = new List;
    bool reachable = true;
};

void swap(unsigned &a, unsigned &b) {
    unsigned temp = a;
    a = b;
    b = temp;
}

void qsort(unsigned *array, unsigned n) {
    unsigned l = 0, r = n - 1, k = n / 2, rep = array[k];
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

void task_1() {
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
}

void task_2() {
    unsigned k, S, counter = -1;
    int N;
    std::cin >> N >> k >> S;
    assert(N <= 1000 and k <= 1000);
    auto *gas_stations = new int[S + 1];
    for (int i = 0; i < S; i++) {
        std::cin >> gas_stations[i];
        assert(0 <= gas_stations[i] <= S);
    }
    gas_stations[S] = N;
    Pointer pointer;
    while (pointer.coordinate < N) {
        for (unsigned i = 0; i < S + 1; i++) {
            if (pointer.coordinate < gas_stations[i] and
            gas_stations[i] <= pointer.coordinate + k) {
                push_back(pointer.available_stations, gas_stations[i]);
            }
        }
        if (length(pointer.available_stations) == 0) {
            std::cout << -1;
            pointer.reachable = false;
            break;
        }
        else {
            pointer.coordinate = get(pointer.available_stations, length(pointer.available_stations) - 1);
            clear(pointer.available_stations);
            counter += 1;
        }
    }
    if (pointer.reachable) {
        std::cout << counter;
    }
}

void task_3() {

}

int main() {
    //task_1();
    //task_2();
    return 0;
}
