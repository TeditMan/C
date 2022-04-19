#include <iostream>
#include <cassert>

struct Node {
    int value = 0;
    Node *next = nullptr;
};

struct Queue {
    unsigned size = 0;
    Node *head = nullptr;
    Node *tail = nullptr;
};

Node* createNode(int value) {
    Node *tmp = new Node{value, nullptr};
    return tmp;
}

Queue* createQueue(int *array, unsigned size) {
    if (size == 0) {
        auto *queue = new Queue;
        return queue;
    }
    else if (size == 1) {
        Node *head_tail = createNode(array[0]);
        auto *queue = new Queue{size, head_tail, head_tail};
        return queue;
    }
    else {
        Node *head = createNode(array[0]);
        Node *tail = createNode(array[size - 1]);
        auto *queue = new Queue{size, head, tail};
        Node *tmp_1 = head, *tmp_2;
        for (int i = 1; i < size - 1; i++) {
            tmp_2 = createNode(array[i]);
            tmp_1->next = tmp_2;
            tmp_1 = tmp_2;
        }
        tmp_2->next = queue->tail;
        return queue;
    }
}

void print(Queue *queue) {
    std::cout << "length = " << queue->size << '\n';
    if (queue->size == 0) {
        std::cout << "empty queue";
        std::cout << "\n\n";
    }
    else {
        Node *tmp = queue->head;
        std::cout << '[' << tmp->value;
        for (int i = 0; i < queue->size - 1; i++) {
            tmp = tmp->next;
            std::cout << ", " << tmp->value;
        }
        std::cout << ']' << "\n\n";
    }
}

void enQueue(Queue *queue, int value) {
    Node *new_node = createNode(value);
    if (queue->size == 0) {
        queue->head = new_node;
        queue->tail = new_node;
        queue->size += 1;
    }
    else {
        queue->tail->next = new_node;
        queue->tail = new_node;
        queue->size += 1;
    }
}

int deQueue(Queue *queue) {
    assert(queue->size > 0 && "empty queue");
    if (queue->size == 1) {
        int tmp_val = queue->head->value;
        delete queue->head;
        queue->head = nullptr;
        queue->tail = nullptr;
        queue->size -= 1;
        return tmp_val;
    }
    else {
        Node *new_head = queue->head->next;
        int tmp_val = queue->head->value;
        delete queue->head;
        queue->head = new_head;
        queue->size -= 1;
        return tmp_val;
    }
}

int front(Queue *queue) {
    return queue->head->value;
}

int rear(Queue *queue) {
    return queue->tail->value;
}

unsigned length(Queue *queue) {
    return queue->size;
}

void clear(Queue *queue) {
    Node *tmp_1 = queue->head, *tmp_2;
    while (tmp_1 != nullptr) {
        tmp_2 = tmp_1->next;
        delete tmp_1;
        tmp_1 = tmp_2;
    }
    queue->size = 0;
    queue->head = nullptr;
    queue->tail = nullptr;
}