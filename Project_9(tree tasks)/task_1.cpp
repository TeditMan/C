#include <iostream>

struct ListNode {
    int key = 0;
    ListNode *left = nullptr;
    ListNode *right = nullptr;
    ListNode *parent = nullptr;
};

struct SimpleTree {
    ListNode *root;
};

ListNode* search(ListNode *root, int key) {
    if (root == nullptr or root->key == key) {
        return root;
    }
    if (key < root->key) {
        return search(root->left, key);
    }
    else {
        return search(root->right, key);
    }
}

ListNode* find_minimum(ListNode *root) {
    ListNode *tmp = root;
    while (tmp->left != nullptr) {
        tmp = tmp->left;
    }
    return tmp;
}

ListNode* find_maximum(ListNode *root) {
    ListNode *tmp = root;
    while (tmp->right != nullptr) {
        tmp = tmp->right;
    }
    return tmp;
}

void insert(ListNode *&root, ListNode *i) {
    ListNode *y = nullptr;
    ListNode *x = root;
    while (x != nullptr) {
        y = x;
        if (i->key < x->key) {
            x = x->left;
        }
        else {
            x = x->right;
        }
    }
    i->parent = y;
    if (y == nullptr) {
        root = i;
    }
    else if (i->key < y->key) {
        y->left = i;
    }
    else {
        y->right = i;
    }
}

void transplant(ListNode *&root, ListNode *high, ListNode *low) {
    if (high->parent == nullptr) {
        root = low;
    }
    else if(high == high->parent->left) {
        high->parent->left = low;
    }
    else {
        high->parent->right = low;
    }
    if (low != nullptr) {
        low->parent = high->parent;
    }
}

void delete_ListNode(ListNode *root, ListNode *i) {
    if (i->left == nullptr) {
        transplant(root, i, i->right);
    }
    else if (i-> right == nullptr) {
        transplant(root, i, i->left);
    }
    else {
        ListNode *tmp = find_minimum(i->right);
        if (tmp->parent != i) {
            transplant(root, tmp, tmp->right);
            tmp->right = i->right;
            tmp->right->parent = tmp;
        }
        transplant(root, i, tmp);
        tmp->left = i->left;
        tmp->left->parent = tmp;
    }
    delete i;
}