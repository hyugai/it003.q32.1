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

    if (x == root->key) {
        return;
    }

    x < root->key ? add_node(root->left, x) : add_node(root->right, x);
}

static int count{0};
void count_node_level_1(TREE t) {
    //
    if (t) {
        count_node_level_1(t->left);

        if (!t->left && t->right || t->left && !t->right) {
            count++;
        }

        count_node_level_1(t->right);
    }
}

void input(TREE &root) {
    int n, x, i{0};

    cin >> n;

    while (i < n) {
        cin >> x;

        add_node(root, x);

        i++;
    }
}

int main() {
    TREE t{nullptr};

    input(t);

    count_node_level_1(t);

    cout << "So node bac 1 cua cay la: " << count << '\n';

    return 0;
}
