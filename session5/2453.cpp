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

void add_node(TREE &p, int x) {
    if (!p) {
        p = create_node(x);
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

int find_route_to_node_x(TREE t, int x) {
    int route_length{0};

    Node *p{t};

    while (p) {
        if (x == p->key) {
            return route_length;
        }

        x < p->key ? p = p->left : p = p->right;

        route_length++;
    }

    return -1;
}

int main() {
    TREE t{nullptr};

    input(t);

    int x;

    while (cin >> x && x) {
        cout << find_route_to_node_x(t, x) << '\n';
    }
}
