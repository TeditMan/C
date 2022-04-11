#include <iostream>

struct Node {
    int value;
    Node *next;
};

struct Queue {
    unsigned size;
    Node *head;
    Node *tail;
};

Node* createNode(int value) {
    Node *tmp = new Node{value, nullptr};
    return tmp;
}

Queue* createQueue(int *array, unsigned size) {
    Node *head = createNode(array[0]);
    Node *tail = createNode(array[size - 1]);
    auto *list = new Queue{size, head, tail};
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

void print(Queue *stack) {
    Node *tmp_1 = stack -> head, *tmp_2;
    while (tmp_1 != nullptr) {
        tmp_2 = tmp_1 -> next;
        std::cout << tmp_1 -> value << ' ';
        tmp_1 = tmp_2;
    }
    std::cout << '\n';
}

void enQueue(Queue *queue, int value) {
    Node *new_node = createNode(value);
    queue -> tail -> next = new_node;
    queue -> tail = new_node;
    queue -> size += 1;
}

void deQueue(Queue *queue) {
    Node *tmp = queue -> head -> next;
    delete queue -> head;
    queue -> head = tmp;
    queue -> size -= 1;
}

int front(Queue *queue) {
    return queue -> head -> value;
}

int rear(Queue *queue) {
    return queue -> tail -> value;
}

unsigned length(Queue *queue) {
    unsigned counter = 0;
    Node *tmp = queue -> head;
    while (tmp != nullptr) {
        tmp = tmp -> next;
        counter += 1;
    }
    return counter;
}

void clear(Queue *queue) {
    Node *tmp_1 = queue -> head, *tmp_2;
    while (tmp_1 != nullptr) {
        tmp_2 = tmp_1 -> next;
        delete tmp_1;
        tmp_1 = tmp_2;
    }
    queue -> head = nullptr;
}

int main() {
    int array[6] = {1, 2, 3, 4, 5, 6};
    Queue *queue = createQueue(array, 6);
    print(queue);

    enQueue(queue, 7);
    print(queue);

    deQueue(queue);
    print(queue);

    std::cout << front(queue) << ' ' << rear(queue) << ' ' << length(queue);

    clear(queue);
    return 0;
}

