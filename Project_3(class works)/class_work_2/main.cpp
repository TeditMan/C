#include <new>
#include <iostream>

struct Node {
    int val;
    Node *next;
};

struct List {
    unsigned size;
    Node *head;
    Node *tail;
};

/*
// pop_back();
// pop_front();
// delete(idx);
// get(idx);
// clear();
*/

Node* createNode(int value) {
    Node *tmp = new Node{value, nullptr};
    return tmp;
}

List* createList(int *array, unsigned size) {
    Node *head = createNode(array[0]);
    Node *tail = createNode(array[size - 1]);
    List *list = new List{size, head, tail};
    Node *tmp1 = head;
    Node *tmp2 = createNode(array[1]);
    tmp1 -> next = tmp2;
    for (int i = 1; i < size - 2; i++) {
        tmp1 = tmp2;
        tmp2 = createNode(array[i + 1]);
        tmp1 -> next = tmp2;
    }
    tmp2 -> next = tail;
    return list;
}

unsigned& length(List *list) {
    return list -> size;
}

int* get_array_of_list(List *list) {
    int *array = new int[length(list)];
    Node *tmp = list -> head;
    array[0] = tmp -> val;
    for (int i = 1; i < length(list); i++) {
        tmp = tmp -> next;
        array[i] = tmp -> val;
    }
    return array;
}

void print_list(List *list) {
    std::cout << "length = " << length(list) << '\n';
    int *array = get_array_of_list(list);
    for (int i = 0; i < length(list); i++) {
        std::cout << array[i] << ' ';
    }
    std::cout << "\n\n";
}

void push_back(List *list, int value) {
    Node *tmp = list -> head;
    for (int i = 0; i < length(list) - 2; i++) {
        tmp = tmp -> next;
    }
    tmp -> next = createNode(list -> tail -> val);
    list -> tail -> val = value;
    tmp -> next -> next = list -> tail;
    length(list) += 1;
}

void push_front(List *&list, int value) {
    unsigned new_length = length(list) + 1;
    int *array_tmp = new int[new_length], *array = get_array_of_list(list);
    array_tmp[0] = value;
    for (int i = 1; i < new_length; i++) {
        array_tmp[i] = array[i - 1];
    }
    list = createList(array_tmp, new_length);
}

void insert(List *&list, unsigned idx, int value) {
    unsigned new_length = length(list) + 1;
    int *array_tmp = new int[new_length], *array = get_array_of_list(list);
    for (int i = 0; i < idx; i++) {
        array_tmp[i] = array[i];
    }
    array_tmp[idx] = value;
    for (int i = 0;  i < new_length - idx - 1; i++) {
        array_tmp[idx + 1 + i] = array[idx + i];
    }
    list = createList(array_tmp, new_length);
}

int main() {
    // initialisation of an array in terms of input
    unsigned size;
    std::cin >> size;
    int *array = new int[size], k;
    for (int i = 0; i < size; i++) {
        std::cin >> k;
        array[i] = k;
    }

    // operations with list
    List *list = createList(array, size);
    print_list(list);

    push_back(list, 10);
    print_list(list);

    push_front(list, 26);
    print_list(list);

    insert(list, 4, 34);
    print_list(list);
    delete list;
    return 0;
}