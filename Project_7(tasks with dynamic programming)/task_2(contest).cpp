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

struct Node {
    int value;
    Node *next;
};

struct List {
    unsigned size = 0;
    Node *head = nullptr;
    Node *tail = nullptr;
};

Node* createNode(int value) {
    Node *tmp = new Node{value, nullptr};
    return tmp;
}

unsigned length(List *list) {
    return list->size;
}

void push_back(List *list, int value) {
    Node *new_node = createNode(value);
    if (length(list) == 0) {
        list->head = new_node;
        list->tail = new_node;
        list->size++;
    }
    else {
        list->tail->next = new_node;
        list->tail = new_node;
        list->size++;
    }
}

void push_front(List *list, int value) {
    Node *new_node = createNode(value);
    if (length(list) == 0) {
        list->head = new_node;
        list->tail = new_node;
        list->size++;
    }
    else {
        new_node->next = list->head;
        list->head = new_node;
        list->size++;
    }
}

void insert(List *list, unsigned idx, int value) {
    assert(idx < length(list) + 1 && "index out of range");
    if (idx == 0) {
        push_front(list, value);
    }
    else if (idx == length(list)) {
        push_back(list, value);
    }
    else {
        Node *new_node = createNode(value);
        Node *tmp_1 = list->head;
        for (int i = 0; i < idx - 1; i++) {
            tmp_1 = tmp_1->next;
        }
        Node *tmp_2 = tmp_1->next;
        tmp_1->next = new_node;
        new_node->next = tmp_2;
        list->size++;
    }
}

int pop_back(List *list) {
    assert(length(list) > 0 && "empty list");
    int tmp_val = list->tail->value;
    delete list->tail;
    if (length(list) == 1) {
        list->head = nullptr;
        list->tail = nullptr;
    }
    else {
        Node *tmp = list->head;
        for (int i = 0; i < length(list) - 2; i++) {
            tmp = tmp->next;
        }
        tmp->next = nullptr;
        list->tail = tmp;
    }
    list->size--;
    return tmp_val;
}

int pop_front(List *list) {
    assert(length(list) > 0 && "empty list");
    int tmp_val = list->head->value;
    delete list->head;
    if (length(list) == 1) {
        list->head = nullptr;
        list->tail = nullptr;
    }
    else {
        Node *new_head = list->head->next;
        list->head = new_head;
    }
    list->size--;
    return tmp_val;
}

int remove(List *list, unsigned idx) {
    assert(idx < length(list) && "index out of range");
    if (idx == 0) {
        return pop_front(list);
    }
    else if (idx == length(list) - 1) {
        return pop_back(list);
    }
    else {
        Node *tmp = list->head;
        for (int i = 0; i < idx - 1; i++) {
            tmp = tmp->next;
        }
        Node *tmp_del = tmp->next;
        int tmp_val = tmp_del->value;
        tmp->next = tmp_del->next;
        delete tmp_del;
        list->size--;
        return tmp_val;
    }
}

int get(List *list, unsigned idx) {
    assert(idx < length(list) && "index is out of range");
    Node *tmp = list->head;
    for (unsigned i = 0; i < idx; i++) {
        tmp = tmp->next;
    }
    return tmp->value;
}

void clear(List *list) {
    Node *tmp_1 = list->head, *tmp_2;
    while (tmp_1 != nullptr) {
        tmp_2 = tmp_1->next;
        delete tmp_1;
        tmp_1 = tmp_2;
    }
    list->size = 0;
    list->head = nullptr;
    list->tail = nullptr;
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

unsigned min_length(List *lengths) {
    if (length(lengths) < 2) {
        return 0;
    }
    unsigned q = 10000, initial_length = length(lengths);
    for (unsigned i = 0; i < initial_length; i++) {
        int tmp = get(lengths, i), prev = 0, next = 0;
        if (i > 0) {
            prev = get(lengths, i - 1);
        }
        if (i < length(lengths) - 1) {
            next = get(lengths, i + 1);
        }

        if (i == 0) {
            remove(lengths, i);
            remove(lengths, i);
        }
        else if (i == length(lengths) - 1) {
            remove(lengths, i);
            remove(lengths, i - 1);
        }
        else {
            remove(lengths, i - 1);
            remove(lengths, i - 1);
            remove(lengths, i - 1);
        }

        q = std::min(q, min_length(lengths) + prev + next);

        if (i == 0) {
            insert(lengths, 0, next);
            insert(lengths, 0, tmp);
        }
        else if (i == length(lengths) - 1) {
            insert(lengths, length(lengths), tmp);
            insert(lengths, length(lengths), next);
        }
        else {
            insert(lengths, i - 1, next);
            insert(lengths, i - 1, tmp);
            insert(lengths, i - 1, prev);
        }
    }
    return q;
}

unsigned get_min_length(int *nails, unsigned size) {
    if (size == 2) {
        return nails[1] - nails[0];
    }
    else {
        qsort(nails, size);
        List *lengths = new List;
        for (unsigned i = 0; i < size - 3; i++) {
            push_back(lengths, nails[i + 2] - nails[i + 1]);
        }
        unsigned answer = min_length(lengths);
        clear(lengths);
        return answer + nails[1] - nails[0] + nails[size - 1] - nails[size - 2];
    }
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