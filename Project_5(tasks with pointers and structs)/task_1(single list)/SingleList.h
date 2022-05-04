#include <iostream>
#include <cassert>

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

List* createList(int *array, unsigned size) {
    if (size == 0) {
        List *list = new List;
        return list;
    }
    else if (size == 1) {
        Node *head_tail = createNode(array[0]);
        List *list = new List{size, head_tail, head_tail};
        return list;
    }
    else {
        Node *head = createNode(array[0]);
        Node *tail = createNode(array[size - 1]);
        List *list = new List{size, head, tail};
        Node *tmp_1 = head, *tmp_2;
        for (unsigned i = 1; i < size - 1; i++) {
            tmp_2 = createNode(array[i]);
            tmp_1->next = tmp_2;
            tmp_1 = tmp_2;
        }
        tmp_2->next = tail;
        return list;
    }
}

unsigned length(List *list) {
    return list->size;
}

void print_list(List *list) {
    std::cout << "length = " << length(list) << '\n';
    if (length(list) == 0) {
        std::cout << "empty list";
        std::cout << "\n\n";
    }
    else {
        Node *tmp = list->head;
        std::cout << '[' << tmp->value;
        for (int i = 0; i < length(list) - 1; i++) {
            tmp = tmp->next;
            std::cout << ", " << tmp->value;
        }
        std::cout << ']' << "\n\n";
    }
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

int* get_array(List *list) {
    int *array = new int[length(list)];
    for (unsigned i = 0; i < length(list); i++) {
        array[i] = get(list, i);
    }
    return array;
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