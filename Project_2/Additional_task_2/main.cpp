#include "Functions.h"

using namespace std;

int main() {
    const int width = 100, height = 1;
    int A[n][3], B[n][3], four[4][2] = {{1,0},{-1,0},{0,1},{0,-1}},
            counter = 0, array_of_the_last_step_1[n][2], array_of_the_last_step_2[n][2];
    bool done_1 = false, done_2 = false;
    PRNG generator;
    fill_movement_bool(A);
    fill_movement_bool(B);
    while (!done_1 or !done_2) {
        done_1 = true, done_2 = true;
        create_config(A, width, height, generator);
        check(A, done_1);
        create_config(B, width, height, generator);
        check(B, done_2);
    }
    check_movement(A, width, height, array_of_the_last_step_1);
    check_movement(B, width, height, array_of_the_last_step_2);
    while (!check_completeness(A) or !check_completeness(B)) {
        for (auto & i : A) {
            cout << i[0] << ' ' << i[1] << ' ' << i[2] << "      ";
        }
        for (auto & i : B) {
            cout << i[0] << ' ' << i[1] << ' ' << i[2] << "      ";
        }
        cout << '\n';
        do_movement(A, four, generator, array_of_the_last_step_1, width, height);
        check_movement(A, width, height, array_of_the_last_step_1);
        do_movement(B, four, generator, array_of_the_last_step_2, width, height);
        check_movement(B, width, height, array_of_the_last_step_2);
        counter += 1;}
    cout << '\n';
    for (auto & i : A) {
        cout << i[0] << ' ' << i[1] << ' ' << i[2] << "      ";
    }
    for (auto & i : B) {
        cout << i[0] << ' ' << i[1] << ' ' << i[2] << "      ";
    }
    cout << '\n' << counter;
    return 0;
}
