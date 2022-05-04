//
// Created by User on 23.04.2022.
//

#pragma ide diagnostic ignored "misc-no-recursion"
#include <iostream>

struct Rod {
    int length;
    int price;
};

int optimize_with_memoization(Rod *table, unsigned table_size, int length, int *memoization_table) {
    if (memoization_table[length] >= 0) {
        return memoization_table[length];
    }
    if (length == 0) {
        memoization_table[length] = 0;
        return memoization_table[length];
    }
    int q = 0;
    for (unsigned i = 0; i < table_size and table[i].length <= length; i++) {
        q = std::max(q, table[i].price + optimize_with_memoization(table, table_size,
                                                                   length - table[i].length, memoization_table));
    }
    memoization_table[length] = q;
    return q;
}

int optimize_m(Rod *table, unsigned table_size, int length) {
    int *array = new int[length + 1];
    for (unsigned i = 0; i <= length; ++i) {
        array[i] = -1;
    }
    int result = optimize_with_memoization(table, table_size, length, array);
    delete []array;
    return result;
}

int main() {
    Rod table[10] = {
            {1, 1},
            {2, 5},
            {3, 8},
            {4, 9},
            {5, 10},
            {6, 17},
            {7, 17},
            {8, 20},
            {9, 24},
            {10, 30}
    };
    int input = -1;
    while (input != 0) {
        std::cin >> input;
        std::cout << optimize_m(table, 10, input) << std::endl;
    }
    return 0;
}