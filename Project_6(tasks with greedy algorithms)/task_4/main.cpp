//
// Created by User on 19.04.2022.
//
#include "C:\Users\User\CLionProjects\C\Project_5(tasks with pointers and structs)\task_1(single list)\SingleList.h"

struct Denominator_array {
    unsigned *array = nullptr;
    unsigned size = 0;
};

struct Egyptian_fraction {
    unsigned num = 0;
    unsigned den = 1;
};

unsigned partial_product(List *array, unsigned idx) {
    unsigned product = 1;
    for (unsigned i = 0; i < idx; i++) {
        product *= get(array, i);
    }
    for (unsigned i = idx + 1; i < length(array); i++) {
        product *= get(array, i);
    }
    return product;
}

bool check_fraction(List *array, unsigned num, unsigned den) {
    unsigned product = 1, sum = 0;
    for (unsigned i = 0; i < length(array); i++) {
        product *= get(array, i);
        sum += partial_product(array, i);
    }
    return sum * den == product * num;
}

int main() {
    Egyptian_fraction e_f;
    List *array = new List;
    std::cin >> e_f.num >> e_f.den;
    double sum = 0, fraction = (double)e_f.num / e_f.den;
    int den_counter = 2;
    while (!check_fraction(array, e_f.num, e_f.den)) {
        if (sum + 1.0 / den_counter <= fraction) {
            push_back(array, den_counter);
            sum += 1.0 / den_counter;
        }
        den_counter += 1;
    }

    Denominator_array answer;
    auto *array_answer = new unsigned[length(array)];
    for (unsigned i = 0; i < length(array); i++) {
        array_answer[i] = get(array, i);
    }
    answer.array = array_answer;
    answer.size = length(array);

    print_list(array);
    return 0;
}