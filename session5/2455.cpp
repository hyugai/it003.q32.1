#include <algorithm>
#include <iostream>

using namespace std;

struct Node {
    int key;
    Node *left{nullptr}, *right{nullptr};
};

typedef Node *TREE;

Node *create_node(int x) {
    //
    Node *p{new Node};

    p->key = x;

    return p;
}

void add_node(TREE &root, int x) {
    if (!root) {
        root = create_node(x);

        return;
    }

    if (x == root->key) {
        return;
    }

    x < root->key ? add_node(root->left, x) : add_node(root->right, x);
}

void input(TREE &root, int &n) {
    cin >> n;

    int x, i{0};

    while (i < n) {
        cin >> x;

        add_node(root, x);

        i++;
    }
}

int bst_height(TREE t) {
    if (!t) {
        return 0;
    }

    return max(bst_height(t->left), bst_height(t->right)) + 1;
}

int main() {
    TREE t{nullptr};
    int n;

    input(t, n);

    cout << "Chieu cao cua cay la: " << bst_height(t) << '\n';

    return 0;
}
