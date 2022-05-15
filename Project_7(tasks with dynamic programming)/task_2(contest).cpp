#include <vector>
#include <sstream>
#include <cassert>
#include <iostream>
using namespace std;
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
void qsort(int *array, unsigned size) {
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

int min_length_c(int*, unsigned, int*);
int min_length_nc(int*, unsigned, int*);

int min_length_nc(int *nails, unsigned size, int *table_m) {
    return min_length_c(nails + 1, size - 1, table_m) + (nails[1] - nails[0]);
}
int min_length_c(int *nails, unsigned size, int *table_m) {
    if (table_m[size] >= 0) {
        return table_m[size];
    }
    if (size == 2) {
        int tmp = nails[1] - nails[0];
        table_m[size] = tmp;
        return tmp;
    }
    if (size == 1) {
        table_m[size] = 0;
        return 0;
    }
    int a = min_length_nc(nails + 1, size - 1, table_m);
    int b = min_length_c(nails + 1, size - 1, table_m) + (nails[1] - nails[0]);
    int result = min(a, b);
    table_m[size] = result;
    return result;
}

unsigned get_min_length(int *nails, unsigned size) {
    qsort(nails, size);
    int *table_m = new int[size + 1];
    for (unsigned i = 0; i <= size; i++) {
        table_m[i] = -1;
    }
    unsigned answer = min_length_c(nails + 1, size - 1, table_m) + nails[1] - nails[0];
    delete[] table_m;
    return answer;
}

int main() {
    string a_string;
    getline(cin, a_string);
    vector<string> vector_array = split(a_string);
    assert(2 <= vector_array.size() and  vector_array.size() <= 100);
    auto *nails = new int[vector_array.size()];
    for (unsigned i = 0; i < vector_array.size(); i++) {
        nails[i] = stoi(vector_array[i]);
        assert(0 <= nails[i] and nails[i] <= 10000);
    }
    std::cout << get_min_length(nails, vector_array.size());
    delete[] nails;
    return 0;
}