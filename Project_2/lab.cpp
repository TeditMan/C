#include "Functions.h"

using namespace std;

int main() {
    const int width = 10, height = 10, s = width * height;
    int A[n][3], four[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}},
    counter = 0, array_of_the_last_step[n][2];
    bool done = false;
    PRNG generator;

    fill_movement_bool(A);
    initGenerator(generator);

    while (!done) {
        done = true;
        create_config(A, width, height, generator);
        check(A, done);
    }
    while (!check_completeness(A)) {
        check_movement(A, width, height, array_of_the_last_step);
        do_movement(A, four, generator, array_of_the_last_step);
        counter += 1;
    }
    cout << counter << '\n' << 100 * n / s;
    return 0;
}
