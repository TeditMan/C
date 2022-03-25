#include "Functions.h"

using namespace std;

int main() {
    const int width = 40, height = 40;
    int A[n][3], four[4][2] = {{1,0},{-1,0},{0,1},{0,-1}},
            counter = 0, array_of_the_last_step[n][2];
    bool done = false;
    PRNG generator;
    fill_movement_bool(A);
    while (!done) {
        done = true;
        create_config(A, width, height, generator);
        check(A, done);
    }
    check_movement(A, width, height, array_of_the_last_step);
    A[0][0] = 1;
    while (!check_completeness(A)) {
        for (auto & i : A) {
            cout << i[0] << ' ' << i[1] << ' ' << i[2] << "      ";
        }
        cout << '\n';
        do_movement(A, four, generator, array_of_the_last_step, width, height);
        check_movement(A, width, height, array_of_the_last_step);
        counter += 1;
    }
    cout << '\n';
    for (auto & i : A) {
        cout << i[0] << ' ' << i[1] << ' ' << i[2] << "      ";
    }
    cout << '\n' << counter;
    return 0;
}