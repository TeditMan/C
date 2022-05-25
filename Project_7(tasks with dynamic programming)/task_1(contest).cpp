#include <vector>
#include <sstream>
#include <cassert>
#include <iostream>
using namespace std;

vector<string> split(const string &text) {
    istringstream is(text);
    string word;
    vector<string> vs;
    while (is >> word) vs.push_back(word);
    return vs;
}

unsigned LIS_with_memoization(int const *sequence, unsigned size, unsigned *max_size, unsigned *memoization_table) {
    if (memoization_table[size] > 0) {
        return memoization_table[size];
    }
    if (size == 1) {
        memoization_table[size] = 1;
        return 1;
    }
    unsigned tmp_value, answer = 1;
    for (int i = 1; i < size; i++) {
        tmp_value = LIS_with_memoization(sequence, i, max_size, memoization_table);
        if (sequence[i - 1] < sequence[size - 1] and tmp_value + 1 > answer) {
            answer = tmp_value + 1;
        }
    }
    if (*max_size < answer) {
        *max_size = answer;
    }
    memoization_table[size] = answer;
    return answer;

}

unsigned LIS(int *sequence, unsigned size) {
    unsigned max = 1;
    auto *memoization_array = new unsigned[size + 1];
    for (unsigned i = 0; i <= size; i++) {
        memoization_array[i] = 0;
    }
    LIS_with_memoization(sequence, size, &max, memoization_array);
    delete[] memoization_array;
    return max;
}

int main() {
    string string_1;
    getline(cin, string_1);
    unsigned n = stoi(string_1);
    assert(n < 100);
    string string_2;
    getline(cin, string_2);
    vector<string> vector_array = split(string_2);
    int *sequence = new int[vector_array.size()];
    for (unsigned i = 0; i < vector_array.size(); i++) {
        sequence[i] = stoi(vector_array[i]);
    }
    cout << LIS(sequence, n);
    delete[] sequence;
    return 0;
}
