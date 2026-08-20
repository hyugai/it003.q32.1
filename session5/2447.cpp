#include <iostream>

using namespace std;

struct Node {
    int key;
    Node *left{nullptr}, *right{nullptr};
};

typedef Node *TREE;

Node *create_node(int x) {
    Node *p{new Node};

    p->key = x;

    return p;
}

void add_node(TREE &root, int x) {
    if (!root) {
        root = create_node(x);

        return;
    }

    if (root->key == x) {
        return;
    }

    x < root->key ? add_node(root->left, x) : add_node(root->right, x);
}

void input(TREE &root) {
    int x;

    while (cin >> x && x) {
        add_node(root, x);
    }
}

void LNR(TREE root) {
    if (root) {
        LNR(root->left);
        cout << root->key << ' ';
        LNR(root->right);
    }
}

void LRN(TREE root) {
    if (root) {
        LRN(root->left);
        LRN(root->right);
        cout << root->key << ' ';
    }
}

void RNL(TREE root) {
    if (root) {
        RNL(root->right);
        cout << root->key << ' ';
        RNL(root->left);
    }
}

void RLN(TREE root) {
    if (root) {
        RLN(root->right);
        RLN(root->left);
        cout << root->key << ' ';
    }
}

void NLR(TREE root) {
    if (root) {
        cout << root->key << ' ';
        NLR(root->left);
        NLR(root->right);
    }
}

void NRL(TREE root) {
    if (root) {
        cout << root->key << ' ';
        NRL(root->right);
        NRL(root->left);
    }
}

int main() {
    TREE t{nullptr};

    input(t);

    cout << "LNR: ";
    LNR(t);
    cout << '\n';

    cout << "LRN: ";
    LRN(t);
    cout << '\n';

    cout << "RNL: ";
    RNL(t);
    cout << '\n';

    cout << "RLN: ";
    RLN(t);
    cout << '\n';

    cout << "NLR: ";
    NLR(t);
    cout << '\n';

    cout << "NRL: ";
    NRL(t);
    cout << '\n';

    return 0;
}
