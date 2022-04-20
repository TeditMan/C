//
// Created by User on 19.04.2022.
//

#include "C:\Users\User\CLionProjects\C\Project_5(tasks with pointers and structs)\task_1(single list)\SingleList.h"
 int main() {
    unsigned X, i, counter = 0, sum = 0;
    std::cin >> X;
    unsigned nominal[5] = {100, 50, 25, 5, 1};
    for(unsigned j : nominal) {
        while (sum + j <= X) {
            sum += j;
            counter += 1;
        }
    }
    std::cout << counter;
    return 0;
}