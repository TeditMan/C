#include <iostream>

struct Node {
    int value;
    Node *next;
};

struct Stack {
    unsigned size;
    Node *head;
};

Node* createNode(int value) {
    Node *tmp = new Node{value, nullptr};
    return tmp;
}

Stack* createStack(int *array, unsigned size) {
    Node *head = createNode(array[0]);
    auto *list = new Stack{size, head};
    Node *tmp_1 = head;
    Node *tmp_2 = createNode(array[1]);
    tmp_1 -> next = tmp_2;
    for (int i = 1; i < size - 1; i++) {
        tmp_1 = tmp_2;
        tmp_2 = createNode(array[i + 1]);
        tmp_1 -> next = tmp_2;
    }
    return list;
}

void push(Stack *stack, int value) {
    Node *new_head = createNode(value);
    Node *tmp = stack -> head;
    stack -> head = new_head;
    new_head -> next = tmp;
    stack -> size += 1;
}

void pop(Stack *stack) {
    Node *tmp_del = stack -> head;
    stack -> head = stack -> head -> next;
    delete tmp_del;
    stack -> size -= 1;
}

int top(Stack *stack) {
    return stack -> head -> value;
}

bool empty(Stack *stack) {
    if (stack -> head == nullptr) {
        return true;
    }
    else return false;
}

void clear(Stack *stack) {
    Node *tmp_1 = stack -> head, *tmp_2;
    while (tmp_1 != nullptr) {
        tmp_2 = tmp_1 -> next;
        delete tmp_1;
        tmp_1 = tmp_2;
    }
    stack -> head = nullptr;
}

void print(Stack *stack) {
    Node *tmp_1 = stack -> head, *tmp_2;
    while (tmp_1 != nullptr) {
        tmp_2 = tmp_1 -> next;
        std::cout << tmp_1 -> value << ' ';
        tmp_1 = tmp_2;
    }
    std::cout << '\n';
}

int main() {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Stack *stack = createStack(array, 10);
    print(stack);
    push(stack, 71);
    print(stack);
    pop(stack);
    print(stack);
    std::cout << top(stack) << '\n';
    std::cout << empty(stack) << ' ';
    clear(stack);
    std::cout << empty(stack);

    clear(stack);
    return 0;
}