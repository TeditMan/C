#include <cassert>
#include <iostream>
using namespace std;

bool check_square(char const *black_pawns, unsigned amount, char const square[2]) {
    for (unsigned i = 0; i < amount; i++) {
        if (square[0] == black_pawns[2 * i] and square[1] == black_pawns[2 * i + 1]) {
            return true;
        }
    }
    return false;
}

void pawn_path(char const *black_pawns, unsigned amount, char const white_pawn[2], unsigned *counter) {
    if (white_pawn[1] == '8') {
        return;
    }
    char possible_square[2];
    unsigned local_counter = 0;
    if (white_pawn[0] != 'a') {
        possible_square[0] = char((int)white_pawn[0] - 1);
        possible_square[1] = (char)(white_pawn[1] + 1);
        if (check_square(black_pawns, amount, possible_square)) {
            local_counter++;
            pawn_path(black_pawns, amount, possible_square, counter);
        }
    }
    possible_square[0] = white_pawn[0];
    possible_square[1] = (char)(white_pawn[1] + 1);
    if (!check_square(black_pawns, amount, possible_square)) {
        local_counter++;
        pawn_path(black_pawns, amount, possible_square, counter);
    }
    if (white_pawn[0] != 'h') {
        possible_square[0] = char((int)white_pawn[0] + 1);
        possible_square[1] = (char)(white_pawn[1] + 1);
        if (check_square(black_pawns, amount, possible_square)) {
            local_counter++;
            pawn_path(black_pawns, amount, possible_square, counter);
        }
    }
    *counter += local_counter - 1;
}

unsigned amount_of_ways(char const *black_pawns, unsigned amount, char white_pawn[2]) {
    auto *counter = new unsigned;
    *counter = 1;
    pawn_path(black_pawns, amount, white_pawn, counter);
    return *counter;
}

int main() {
    string string_1;
    getline(cin, string_1);
    unsigned n = stoi(string_1);
    assert(n <= 63);
    string tmp;
    auto black_pawns = new char[2 * n];
    for (unsigned i = 0; i < n; i++) {
        getline(cin, tmp);
        black_pawns[2 * i] = tmp[0];
        black_pawns[2 * i + 1] = tmp[1];
    }
    char white_pawn[2];
    getline(cin, tmp);
    white_pawn[0] = tmp[0];
    white_pawn[1] = tmp[1];
    cout << amount_of_ways(black_pawns, n, white_pawn);
    return 0;
}