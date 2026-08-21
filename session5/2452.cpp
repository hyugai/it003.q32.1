/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported
include
class template
[
]
###End banned keyword*/

#include <cstdio>
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

void add_node(TREE &p, int x) {
    if (!p) {
        p = create_node(x);

        return;
    }

    if (x == p->key) {
        return;
    }

    x < p->key ? add_node(p->left, x) : add_node(p->right, x);
}

void input(TREE &t) {
    int x;

    while (cin >> x && x) {
        add_node(t, x);
    }
}

void LNR(TREE t) {
    if (t) {
        LNR(t->left);
        cout << t->key << ' ';
        LNR(t->right);
    }
}

int find_level_node_x(TREE t, int x) {
    //
    Node *p{t};

    while (p) {
        if (x == p->key) {
            if (p->left && p->right) {
                return 2;
            }

            if (p->left || p->right) {
                return 1;
            }

            return 0;
        }

        x < p->key ? p = p->left : p = p->right;
    }

    return 0;
}

int main() {
    TREE t{nullptr};

    input(t);

    LNR(t);
    cout << '\n';

    int x;

    while (cin >> x && x) {
        printf("Node %d co bac la %d.\n", x, find_level_node_x(t, x));
    }
}
