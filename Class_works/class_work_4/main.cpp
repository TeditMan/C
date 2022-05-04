#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

struct Thread {
    unsigned start = 0;
    unsigned end = 0;
    unsigned length = end - start;
};

vector<string> split(const string& text) {
    istringstream is(text);
    string word;
    vector<string> vs;
    while (is >> word) vs.push_back(word);
    return vs;
}

void swap(unsigned &a, unsigned &b) {
    unsigned temp = a;
    a = b;
    b = temp;
}

void qsort(unsigned *array, unsigned size) {
    if (size < 2) {
        return;
    }
    unsigned left_pointer = 0, right_pointer = size - 2;
    while (left_pointer < right_pointer or (size == 2 and left_pointer == right_pointer and array[0] <= array[1])) {
        while (array[left_pointer] <= array[size - 1] and left_pointer < size - 1) {
            left_pointer++;
        }
        while (array[right_pointer] > array[size - 1] and right_pointer > 0) {
            right_pointer--;
        }
        if (left_pointer < right_pointer) {
            swap(array[left_pointer], array[right_pointer]);
        }
    }
    swap(array[left_pointer], array[size - 1]);
    qsort(array, left_pointer);
    qsort(array + left_pointer + 1, size - left_pointer - 1);
}

unsigned get_max_length(unsigned *nails, unsigned size) {

}

int main() {
    string a_string;
    getline(cin, a_string);
    vector<string> vector_array = split(a_string);
    assert(2 <= vector_array.size() and  vector_array.size() <= 100);
    auto *nails = new unsigned[vector_array.size()];
    for (unsigned i = 0; i < vector_array.size(); i++) {
        nails[i] = stoi(vector_array[i]);
        assert(nails[i] <= 10000);
    }
    qsort(nails, vector_array.size());

    vector<Thread> array_of_threads;
    return 0;
}