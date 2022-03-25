#include "Functions.h"

using namespace std;

int main() {
    const int width = 10, height = 10;
    int A[n][3], four[4][2] = {{1,0},{-1,0},{0,1},{0,-1}},
    counter = 0, array_of_the_last_step[n][2];
    PRNG generator;
    for (int ss = 0; ss < 1000; ss++) {
        fill_movement_bool(A);
        config(A, width, height, generator);
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
        counter = 0;
    }
    cout << "end";
    return 0;
}