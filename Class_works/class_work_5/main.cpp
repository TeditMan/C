#include <vector>
#include <sstream>
#include <iostream>
#include <cassert>
#include "C:\Users\User\CLionProjects\C\Project_5(tasks with pointers and structs)\task_1(single list)\SingleList.h"
using namespace std;

vector<string> split(const string& text) {
    istringstream is(text);
    string word;
    vector<string> vs;
    while (is >> word) vs.push_back(word);
    return vs;
}

void swap(int &a, int &b) {
    int temp = a;
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

int find_max(List *sequence) {
    int *tmp = get_array(sequence);
    qsort(tmp, length(sequence));
    int answer = tmp[length(sequence) - 1];
    delete[] tmp;
    return answer;
}

unsigned longest_subsequence(List *sequence) {
    if (length(sequence) == 1) {
        return 1;
    }
    unsigned q = 0;
    for (unsigned i = 0; i < length(sequence); i++) {
        int k = remove(sequence, i);
        unsigned s_length = longest_subsequence(sequence);

        if (find_max(sequence) < k) {
            s_length++;
        }

        insert(sequence, i, k);
        q = std::max(q, s_length);
    }
    return q;
}

unsigned longest_subsequence_1(List *sequence) {

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
    List *sequence_l = createList(sequence, n);


    std::cout << longest_subsequence(sequence_l);
    return 0;
}