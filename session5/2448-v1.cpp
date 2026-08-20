/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported
include
class template
[
]
###End banned keyword*/

#include <iostream>

using namespace std;

// ###INSERT CODE HERE -

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

void input_bst(TREE &root) {
    int x;

    while (cin >> x && x) {
        add_node(root, x);
    }
}

bool my_bs(TREE t, int x) {
    Node *p{t};

    while (p) {
        if (x == p->key) {
            return true;
        }

        x < p->key ? p = p->left : p = p->right;
    }

    return false;
}

static string s{""};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    TREE t{nullptr};

    input_bst(t);

    int x;
    while (cin >> x && x) {
        s += (my_bs(t, x) ? "YES\n" : "NO\n");
    }

    cout << s;

    return 0;
}
