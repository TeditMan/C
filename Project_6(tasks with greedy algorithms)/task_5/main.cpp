//
// Created by User on 19.04.2022.
//
#include <iostream>

unsigned min_amount(unsigned number, unsigned const *nominal, unsigned amount_of_nominal) {
    unsigned sum = 0, counter = 0;
    for(unsigned j = 0; j < amount_of_nominal; j++) {
        while (sum + nominal[j] <= number) {
            sum += nominal[j];
            counter += 1;
        }
    }
    return counter;
}

 int main() {
    unsigned X;
    std::cin >> X;
    unsigned nominal[5] = {100, 50, 25, 5, 1};
    std::cout << min_amount(X, nominal, 5);
    return 0;
}