#include <new>
#include <iostream>

struct Node {
    int value;
    Node *next;
};

struct List {
    unsigned size;
    Node *head;
    Node *tail;
};

Node* createNode(int value) {
    Node *tmp = new Node{value, nullptr};
    return tmp;
}

List* createList(int *array, unsigned size) {
    Node *head = createNode(array[0]);
    Node *tail = createNode(array[size - 1]);
    List *list = new List{size, head, tail};
    Node *tmp_1 = head;
    Node *tmp_2 = createNode(array[1]);
    tmp_1 -> next = tmp_2;
    for (int i = 1; i < size - 2; i++) {
        tmp_1 = tmp_2;
        tmp_2 = createNode(array[i + 1]);
        tmp_1 -> next = tmp_2;
    }
    tmp_2 -> next = tail;
    return list;
}

unsigned length(List *list) {
    unsigned counter = 0;
    Node *tmp = list -> head;
    while (tmp != nullptr) {
        tmp = tmp -> next;
        counter += 1;
    }
    return counter;
}

void print_list(List *list) {
    Node *tmp = list -> head;
    std::cout << "length = " << list -> size << '\n';
    std::cout << tmp -> value << ' ';
    for (int i = 0; i < length(list) - 1; i++) {
        tmp = tmp -> next;
        std::cout << tmp -> value << ' ';
    }
    std::cout << "\n\n";
}

void push_back(List *list, int value) {
    Node *new_tail = createNode(value);
    list -> tail -> next = new_tail;
    list -> tail = new_tail;
    list -> size += 1;
}

void push_front(List *list, int value) {
    Node *new_head = createNode(value);
    Node *tmp = list -> head;
    list -> head = new_head;
    list -> head -> next = tmp;
    list -> size += 1;

}

void insert(List *list, unsigned idx, int value) {
    Node *new_node = createNode(value);
    Node *tmp = list -> head;
    for (int i = 0; i < idx - 1; i++) {
        tmp = tmp -> next;
    }
    Node *tmp_1 = tmp;
    tmp = tmp -> next;
    Node *tmp_2 = tmp;
    tmp_1 -> next = new_node;
    new_node -> next = tmp_2;
    list -> size += 1;
}

int pop_back(List *list) {
    Node *tmp = list -> head;
    for (int i = 0; i < length(list) - 2; i++) {
        tmp = tmp -> next;
    }
    int tmp_val = tmp -> next -> value;
    delete tmp -> next;
    tmp -> next = nullptr;
    list -> tail = tmp;
    list -> size -= 1;
    return tmp_val;
}

int pop_front(List *list) {
    Node *tmp = list -> head -> next;
    int tmp_val = list -> head -> value;
    delete list -> head;
    list -> head = tmp;
    list -> size -= 1;
    return tmp_val;
}

int remove(List *list, unsigned idx) {
    Node *tmp = list -> head;
    for (int i = 0; i < idx - 1; i++) {
        tmp = tmp -> next;
    }
    Node *tmp_del = tmp -> next;
    tmp -> next = tmp -> next -> next;
    int tmp_val = tmp_del -> value;
    delete tmp_del;
    list -> size -= 1;
    return tmp_val;
}

int get(List *list, unsigned idx) {
    Node *tmp = list -> head;
    for (unsigned i = 0; i < idx; i++) {
        tmp = tmp -> next;
    }
    return tmp -> value;
}

void clear(List *list) {
    Node *tmp_1 = list -> head, *tmp_2;
    while (tmp_1 != nullptr) {
        tmp_2 = tmp_1 -> next;
        delete tmp_1;
        tmp_1 = tmp_2;
    }
    list -> head = nullptr;
}

int main() {
    // initialisation of an array with input
    unsigned size;
    std::cin >> size;
    int *array = new int[size], k;
    for (int i = 0; i < size; i++) {
        std::cin >> k;
        array[i] = k;
    }
    List *list = createList(array, size);
    print_list(list);

    // operations with list
    push_back(list, 10);
    print_list(list);

    push_front(list, 26);
    print_list(list);

    insert(list, 1, 34);
    print_list(list);

    pop_back(list);
    print_list(list);

    pop_front(list);
    print_list(list);

    remove(list, 2);
    print_list(list);

    std::cout << "length = " << length(list) << '\n' << "list member with index 2: " << get(list, 2) << '\n';

    clear(list);
    return 0;
}