#include "Functions.h"

using namespace std;

int main() {
    const int width = 20, height = 20;
    int A[n][3], four[4][2] = {{1,0},{-1,0},{0,1},{0,-1}},
    counter = 0, array_of_the_last_step[n][2];
    bool done = false;
    PRNG generator;
    for (int ss = 0; ss < 1000; ss++) {
        fill_movement_bool(A);
        while (!done) {
            done = true;
            create_config(A, width, height, generator);
            check(A, done);
        }
        check_movement(A, width, height, array_of_the_last_step);
        while (!check_completeness(A)) {
            do_movement(A, four, generator, array_of_the_last_step, width, height);
            check_movement(A, width, height, array_of_the_last_step);
            counter += 1;
        }
        cout << counter << ", ";
        if (ss % 18 == 0 and ss != 0) {
            cout << '\n';
        }
        done = false;
        counter = 0;
    }
    cout << "end";
    return 0;
}