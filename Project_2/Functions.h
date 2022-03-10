#include <iostream>
#include <random>
#include <cassert>
const int n = 90;

struct PRNG {
    std::mt19937 engine;
};

void initGenerator(PRNG &generator) {
    std::random_device device;
    generator.engine.seed(device());
}

int random(PRNG &generator, int minValue, int maxValue) {
    assert(minValue <= maxValue);
    std::uniform_int_distribution<int> distribution(minValue, maxValue);
    return distribution(generator.engine);
}

void fill_movement_bool(int (&A)[n][3]) {
    for (auto & i : A) {
        i[2] = 1;
    }
}

bool check(int A[n][3], int a, int b, int edge) {
    bool _bool_ = true;
    for (int i = 0; i < edge; i++) {
        if (A[i][0] == a and A[i][1] == b) {
            _bool_ = false;
            break;
        }
    }
    return _bool_;
}
void config(int (&A)[n][3], const int width, const int height, PRNG generator) {
    initGenerator(generator);
    for (int i = 0; i < n; i++) {
        int a = random(generator, 1, width);
        int b = random(generator, 1, height);
        while (!check(A, a, b, i)) {
            a = random(generator, 1, width);
            b = random(generator, 1, height);
        }
        A[i][0] = a;
        A[i][1] = b;
    }
}

void check_movement(int (&A)[n][3], const int width, const int height, int a_o_t_l_s[n][2]) {
    int temporary_array[3] = {-1, -1, -1}, k;
    for (int i = 0; i < n - 1; i++) {
        for (int & z : temporary_array) {
            z = -1;
        }
        k = 0;
        for (int j = i + 1; j < n; j++) {
            if (A[i][0] == A[j][0] and A[i][1] == A[j][1]) {
                temporary_array[k] = j;
                k += 1;
            }
        }
        for (int &l : temporary_array) {
            if (l != -1) {
                A[l][0] -= a_o_t_l_s[l][0];
                A[l][1] -= a_o_t_l_s[l][0];
            }
        }
    }
    if (width == 1) {
        if (height == 1) {
            A[0][2] = 0;
        }
        else {
            for (auto & i : A) {
                if (i[1] == 1 or i[1] == height) {
                    i[2] = 0;
                }
            }
        }
    }
    else if (height == 1) {
        for (auto & i : A) {
            if (i[0] == 1 or i[0] == width) {
                i[2] = 0;
            }
        }
    }
    else {
        for (auto & i : A) {
            if (i[0] == 1 or i[0] == width or i[1] == 1 or i[1] == height) {
                i[2] = 0;
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((abs(A[i][0] - A[j][0]) + abs(A[i][1] - A[j][1])) == 1) {
                A[i][2] = 0;
                A[j][2] = 0;
            }
        }
    }
}

void do_movement(int (&A)[n][3], int a_four[4][2], PRNG generator, int (&a_o_t_l_s)[n][2], const int width, const int height) {
    initGenerator(generator);
    for (int i = 0; i < n; i++) {
        if (A[i][2] == 1) {
            int var_int;
            if (width == 1) {
                var_int = random(generator, 2, 3);
            }
            else if (height == 1) {
                var_int = random(generator, 0, 1);
            }
            else {
                var_int = random(generator, 0, 3);
            }
            A[i][0] += a_four[var_int][0];
            A[i][1] += a_four[var_int][1];
            a_o_t_l_s[i][0] = a_four[var_int][0];
            a_o_t_l_s[i][1] = a_four[var_int][1];
        }
    }
}

bool check_completeness(int A[n][3]) {
    int counter = 0;
    for (int i = 0; i < n; i++) {
        if (A[i][2] == 0) {
            counter += 1;
        }
    }
    if (counter == n) {
        return true;
    }
    else {
        return false;
    }
}

void print_A(int A[n][3]) {
    for (int i = 0; i < n; i++) {
        std::cout << A[i][0] << "  " << A[i][1] << '\n';
    }
}