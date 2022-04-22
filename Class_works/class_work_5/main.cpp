#include <iostream>

struct Rod {
    int length;
    int price;
};

int cut_rod_recursive(Rod *p, int n) {
    if (n == 0) {
        return 0;
    }
    int q = -1;
    for (auto i = 1; p[i - 1].length <= 10 && i <= n; ++i) {
        q = std::max(q, p[i - 1].price + cut_rod_recursive(p, n - i));
    }
    return q;
}

int cut_rod_helper(Rod *p, int n, int *memo) {
    if (memo[n] >= 0) {
        return memo[n];
    }
    if (n == 0) {
        memo[n] = 0;
        return memo[n];
    }
    int q = -1;
    for (auto i = 1; p[i - 1].length <= 10 && i <= n; ++i) {
        q = std::max(q, p[i - 1].price + cut_rod_helper(p, n - i, memo));
    }
    memo[n] = q;
    return q;
}

int cut_rod_memoization(Rod *p, int n) {
    int *array = new int[n + 1];
    for (auto i = 0; i <= n; ++i) {
        array[i] = -1;
    }
    int result = cut_rod_helper(p, n, array);
    delete []array;
    return result;
}

int main() {
    Rod rods[] = {
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
    std::cout << cut_rod_recursive(rods, 3) << '\n';
    //std::cout << cut_rod_memoization(rods, 30) << '\n';
}