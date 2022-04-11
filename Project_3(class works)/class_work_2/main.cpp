#include <iostream>


unsigned long long pow(unsigned long long a, int i) {
    unsigned long long counter = 1;
    for (int j = 0; j < i; j++) {
        counter *= a;
    }
    return counter;
}


unsigned long long check(unsigned long long n) {
    int i = 1;
    while (n % pow(2, i) == 0 and (n % pow(2, i + 1)) == 0 and n >= pow(2, i + 1)) {
        i += 1;
    }
    return i;
}

int main() {
    unsigned long long n, counter = 0;
    std::cin >> n;
    for (unsigned i = 2; i <= n; i += 2) {
        counter += check(i);
    }
    std::cout << counter;
    return 0;
}