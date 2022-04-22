#include <iostream>
#include <cassert>

using std::cout;
using std::cin;
using std::endl;

struct Node {
    int value = 0;
    Node *next = nullptr;
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
    if (list->size == 0) {
        list->head = new_node;
        list->tail = new_node;
        list->size += 1;
    }
    else {
        list->tail->next = new_node;
        list->tail = new_node;
        list->size += 1;
    }
}

int get(List *list, unsigned idx) {
    assert(idx < list->size && "index is out of range");
    Node *tmp = list->head;
    for (unsigned i = 0; i < idx; i++) {
        tmp = tmp->next;
    }
    return tmp->value;
}

int* compress(int **matrix, int n, int m) {
    List *array = new List;
    unsigned counter = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] != 0) {
                push_back(array, matrix[i][j]);
                counter += 1;
            }
        }
        if (counter != 3) {
            return nullptr;
        }
        counter = 0;
    }
    for (unsigned i = 0; i < n; i++) {
        delete matrix[i];
    }
    delete[] matrix;
    int *compressed = new int[length(array)];
    for (unsigned i = 0; i < length(array); i++) {
        compressed[i] = get(array, i);
    }
    return compressed;
}

int main() {
    int n, m;
    cin >> n >> m;
    int **a = new int *[n];
    for (int i = 0; i < n; i++)
        a[i] = new int[m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    int *compressed = compress(a, n, m);

    if (!compressed) return 0;

    for (int i = 0; i < n * 3; i++)
        cout << compressed[i] << " ";
    cout << endl;

    delete[] compressed;
    return 0;
}