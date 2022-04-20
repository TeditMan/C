#include <string>
#include <iostream>
#include "C:\Users\User\CLionProjects\C\Project_5(tasks with pointers and structs)\task_1(single list)\SingleList.h"

struct Pointer{
    unsigned coordinate = 0;
    List *available_stations = new List;
    bool reachable = true;
};

int main() {
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
    return 0;
}