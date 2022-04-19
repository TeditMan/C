#include <iostream>
#include <cassert>
struct Node {
    int value = 0;
    Node *next = nullptr;
};

struct Stack {
    unsigned size = 0;
    Node *head = nullptr;
};

Node* createNode(int value) {
    Node *tmp = new Node{value, nullptr};
    return tmp;
}

Stack* createStack(int *array, unsigned size) {
    if (size == 0) {
        auto *stack = new Stack;
        return stack;
    }
    else {
        Node *head = createNode(array[0]);
        auto *stack = new Stack{size, head};
        Node *tmp_1 = head, *tmp_2;
        for (unsigned i = 1; i < size; i++) {
            tmp_2 = createNode(array[i]);
            tmp_1->next = tmp_2;
            tmp_1 = tmp_2;
        }
        return stack;
    }
}

void push(Stack *stack, int value) {
    Node *new_head = createNode(value);
    new_head->next = stack->head;
    stack->head = new_head;
    stack->size += 1;
}

int pop(Stack *stack) {
    assert(stack->size > 0 && "empty stack");
    Node *new_head = stack->head->next;
    int tmp_val = stack->head->value;
    delete stack->head;
    stack->head = new_head;
    stack->size -= 1;
    return tmp_val;
}

int top(Stack *stack) {
    return stack->head->value;
}

bool empty(Stack *stack) {
    if (stack->head == nullptr) {
        return true;
    }
    else return false;
}

void clear(Stack *stack) {
    Node *tmp_1 = stack->head, *tmp_2;
    while (tmp_1 != nullptr) {
        tmp_2 = tmp_1->next;
        delete tmp_1;
        tmp_1 = tmp_2;
    }
    stack->size = 0;
    stack->head = nullptr;
}

void print(Stack *stack) {
    std::cout << "length = " << stack->size << '\n';
    if (stack->size == 0) {
        std::cout << "empty stack";
        std::cout << "\n\n";
    }
    else {
        Node *tmp = stack->head;
        std::cout << '[' << tmp->value;
        for (int i = 0; i < stack->size - 1; i++) {
            tmp = tmp->next;
            std::cout << ", " << tmp->value;
        }
        std::cout << ']' << "\n\n";
    }
}