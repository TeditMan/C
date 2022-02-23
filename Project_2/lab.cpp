#include "Functions.h"

using namespace std;

int main() {
    const int width = 100, height = 1, s = width * height;
    int A[n][3], four[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}},
    counter = 0, array_of_the_last_step[n][2];
    bool done = false;
    PRNG generator;
    fill_movement_bool(A);
    while (!done) {
        done = true;
        create_config(A, width, height, generator);
        check(A, done);
    }
    while (!check_completeness(A)) {
        check_movement(A, width, height, array_of_the_last_step);
        do_movement(A, four, generator, array_of_the_last_step, width, height);
        counter += 1;
    }
    double n_d = n, s_d = s, ratio = n_d / s_d;
    cout << "rules are different for case where width = 1 or height = 1, and where width > 1 and height > 1 \n";
    cout << "time: " <<  counter << '\n' << "ratio of number of empty cells to area: " << ratio;
    return 0;
}