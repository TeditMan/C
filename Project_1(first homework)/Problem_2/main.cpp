#include <iostream>

int main() {
    int n, counter_open = 0, counter_close = 0;
    std::cin >> n;
    if (n % 2 != 0) {
        std::cout << "sequence cannot be correct\n";
    }
    else {
        for (int i = 0; i < n; i++) {
            char k;
            std::cin >> k;
            if (k == '(') {
                counter_open += 1;
            } else {
                if (k == ')') {
                    counter_close += 1;
                } else {
                    std::cout << "incorrect input" << '\n';
                    break;
                }
            }
        }
        if (counter_open == counter_close) {
            std::cout << "sequence is correct" << '\n';
        } else {
            std::cout << "sequence is incorrect";
        }
    }
    return 0;
}
