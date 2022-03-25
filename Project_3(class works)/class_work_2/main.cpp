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
// push_back(val);
// push_front(val);
// insert(idx, val);
// pop_back();
// pop_front();
// delete(idx);
// get(idx);
// clear();
// print();
int length(List *l) {
    return l->size;
}
*/

Node* createNode(int value) {
    Node *tmp = new Node{value, nullptr};
    return tmp;
}

List* createList(int *array, unsigned size) {
    Node *head = createNode(array[0]);
    Node *tail = createNode(array[size - 1]);
    List *list = new List{size, head, tail};
    for (int i = 0; i < (list -> size) - 2; i++) {
        ((list -> head) + i) = ((list -> head) + i) -> next;
        ((list -> head) + i) -> next = createNode(array[1 + i]);
    }
    return list;
}

void print_list(List *list) {
    std::cout << list -> head -> val << ' ';
    for (int i = 0; i < list -> size - 2; i++) {
        std::cout << ((list -> head) + i) -> next -> val << ' ';
    }
    std::cout << list -> tail -> val << ' ';
}

void push_back(List *list, int value) {
    int tmp = list->head->val;
    for (int i = 1; i < (list -> size) - 1; i++) {
        (list->head + i)->val = tmp;
        tmp = (list->head + i)->val;
    }
    list -> head -> val = value;

}
int main() {
    unsigned size = 10;
    int array_0[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    List *list = createList(array_0, size);
    print_list(list);
    // std::cout << list -> head -> next -> val;
    delete list;
    return 0;
}