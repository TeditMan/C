#include <iostream>
#include <cassert>
struct Node {
    int value = 0;
    Node *next = nullptr;
    Node *prev = nullptr;
};

struct DoubleList {
    unsigned size = 0;
    Node *head = nullptr;
    Node *tail = nullptr;
};

Node* createNode(int value) {
    Node *tmp = new Node{value, nullptr, nullptr};
    return tmp;
}

DoubleList* createList(int *array, unsigned size) {
    if (size == 0) {
        auto *list = new DoubleList;
        return list;
    }
    else if (size == 1) {
        Node *head_tail = createNode(array[0]);
        auto *list = new DoubleList{size, head_tail, head_tail};
        return list;
    }
    else {
        Node *head = createNode(array[0]);
        Node *tail = createNode(array[size - 1]);
        auto *list = new DoubleList{size, head, tail};
        Node *tmp_1 = head, *tmp_2;
        for (unsigned i = 1; i < size - 1; i++) {
            tmp_2 = createNode(array[i]);
            tmp_1->next = tmp_2;
            tmp_2->prev = tmp_1;
            tmp_1 = tmp_2;
        }
        tmp_2->next = tail;
        tail->prev = tmp_2;
        return list;
    }
}

unsigned length(DoubleList *list) {
    return list->size;
}

void print_list(DoubleList *list) {
    std::cout << "length = " << list->size << '\n';
    if (list->size == 0) {
        std::cout << "empty list";
        std::cout << "\n\n";
    }
    else {
        Node *tmp = list->head;
        std::cout << '[' << tmp->value;
        for (int i = 0; i < list->size - 1; i++) {
            tmp = tmp->next;
            std::cout << ", " << tmp->value;
        }
        std::cout << ']' << "\n\n";
    }
}

void print_reverse(DoubleList *list) {
    std::cout << "length = " << list->size << '\n';
    if (list->size == 0) {
        std::cout << "empty list";
        std::cout << "\n\n";
    }
    else {
        Node *tmp = list->tail;
        std::cout << '[' << tmp->value;
        for (int i = 0; i < list->size - 1; i++) {
            tmp = tmp->prev;
            std::cout << ", " << tmp->value;
        }
        std::cout << ']' << "\n\n";
    }
}

void push_back(DoubleList *list, int value) {
    Node *new_node = createNode(value);
    if (list->size == 0) {
        list->head = new_node;
        list->tail = new_node;
        list->size += 1;
    }
    else {
        list->tail->next = new_node;
        new_node->prev = list->tail;
        list->tail = new_node;
        list->size += 1;
    }
}

void push_front(DoubleList *list, int value) {
    Node *new_node = createNode(value);
    if (list->size == 0) {
        list->head = new_node;
        list->tail = new_node;
        list->size += 1;
    }
    else {
        list->head->prev = new_node;
        new_node->next = list->head;
        list->head = new_node;
        list->size += 1;
    }
}

void insert(DoubleList *list, unsigned idx, int value) {
    assert(idx < list->size + 1 && "index out of range");
    if (idx == 0) {
        push_front(list, value);
    }
    else if (idx == list->size) {
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
        new_node->prev = tmp_1;
        new_node->next = tmp_2;
        tmp_2->prev = new_node;
        list->size += 1;
    }
}

int pop_back(DoubleList *list) {
    assert(list->size > 0 && "empty list");
    if (list->size == 1) {
        int tmp_val = list->tail->value;
        delete list->tail;
        list->head = nullptr;
        list->tail = nullptr;
        list->size -= 1;
        return tmp_val;
    }
    else {
        Node *new_tail = list->tail->prev;
        int tmp_val = list->tail->value;
        delete list->tail;
        list->tail = new_tail;
        list->tail->next = nullptr;
        list->size -= 1;
        return tmp_val;
    }
}

int pop_front(DoubleList *list) {
    assert(list->size > 0 && "empty list");
    if (list->size == 1) {
        int tmp_val = list->head->value;
        delete list->head;
        list->head = nullptr;
        list->tail = nullptr;
        list->size -= 1;
        return tmp_val;
    }
    else {
        Node *new_head = list->head->next;
        int tmp_val = list->head->value;
        delete list->head;
        list->head = new_head;
        list->head->prev = nullptr;
        list->size -= 1;
        return tmp_val;
    }
}

int remove(DoubleList *list, unsigned idx) {
    assert(idx < list->size && "index out of range");
    if (idx == 0) {
        return pop_front(list);
    }
    else if (idx == list->size - 1) {
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
        tmp_del->next->prev = tmp;
        delete tmp_del;
        list->size -= 1;
        return tmp_val;
    }
}

int get(DoubleList *list, unsigned idx) {
    assert(idx < list->size && "index is out of range");
    Node *tmp = list->head;
    for (unsigned i = 0; i < idx; i++) {
        tmp = tmp->next;
    }
    return tmp->value;
}

void clear(DoubleList *list) {
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

int main() {
    // initialisation of an array with input
    unsigned size;
    std::cin >> size;
    int *array = new int[size], k;
    for (int i = 0; i < size; i++) {
        std::cin >> k;
        array[i] = k;
    }
    DoubleList *list = createList(array, size);
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

    print_reverse(list);

    std::cout << "length = " << length(list) << '\n' << "list member with index 2: " << get(list, 2) << '\n';

    clear(list);
    return 0;
}