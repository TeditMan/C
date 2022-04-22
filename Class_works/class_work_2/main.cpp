#include <iostream>

unsigned long long pow(unsigned long long a, unsigned i) {
    unsigned long long counter = 1;
    for (int j = 0; j < i; j++) {
        counter *= a;
    }
    return counter;
}

unsigned greatest_power(unsigned long long a) {
    unsigned counter = 1;
    while (a >= pow(2, counter)) {
        counter++;
    }
    return --counter;
}

unsigned long long calculate_power_of_2(unsigned power) {
    unsigned long long sum = power;
    power -= 1;
    unsigned counter = 0;
    while (power > 0) {
        sum += pow(2, counter) * power;
        power--;
        counter++;
    }
    return sum;
}

void calculate(unsigned long long a, unsigned long long &sum) {
    if (a < 2) {
        return;
    }
    unsigned tmp_1 = greatest_power(a);
    unsigned long long tmp_2 = calculate_power_of_2(tmp_1);
    sum += tmp_2;
    calculate(a - pow(2, tmp_1), sum);
}

int main() {
    unsigned long long n, sum = 0;
    std::cin >> n;
    calculate(n, sum);
    std::cout << sum;
    return 0;
}