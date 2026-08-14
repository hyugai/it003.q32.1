#include <iostream>

using namespace std;

struct Node {
    int key;

    Node *left{nullptr};
    Node *right{nullptr};
};

typedef Node *TREE;

void create_tree(TREE &t) { t = nullptr; }

Node *create_node(int x) {
    //
    Node *p{new Node};

    p->key = x;

    return p;
}

bool is_tree_empty(TREE t) { return (t == nullptr ? true : false); }

void traverse_NLR(TREE t) {
    //
    cout << t->key;

    traverse_NLR(t->left);

    traverse_NLR(t->right);
}

void traverse_LNR(TREE t) {
    //
    traverse_LNR(t->left);

    cout << t->key;

    traverse_LNR(t->right);
}

void traverse_LRN(TREE t) {
    //
    traverse_LRN(t->left);

    traverse_LRN(t->right);

    cout << t->key;
}

int find_minimum(TREE t) {
    if (!t->left) {
        return t->key;
    }

    return find_minimum(t->left);
}

int find_maximum(TREE t) {
    if (!t->right) {
        return t->key;
    }

    return find_maximum(t->right);
}

int count_nodes(TREE t) {
    if (!t->left && !t->right) {
        return 1;
    }

    if (!t->left) {
        return 1 + count_nodes(t->right);
    }

    if (!t->right) {
        return 1 + count_nodes(t->left);
    }

    return 1 + count_nodes(t->left) + count_nodes(t->right);
}
