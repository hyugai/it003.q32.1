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

void input(TREE &root, int &n) {
    cin >> n;

    int x, i{0};

    while (i < n) {
        cin >> x;
        add_node(root, x);

        i++;
    }
}

static int leaves{0};
static string s{""};

void LNR(TREE t) {
    if (t) {
        LNR(t->left);
        if (!t->left && !t->right) {
            leaves++;

            s += to_string(t->key) + ' ';
        }
        LNR(t->right);
    }
}

int main() {
    //
    int n;
    TREE t{nullptr};

    input(t, n);

    LNR(t);

    cout << leaves << '\n' << s << '\n';

    return 0;
}
