#include <cstdio>
#include <iostream>
#include <map>

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
    int n, i{0}, x;

    cin >> n;

    while (i < n) {
        cin >> x;
        add_node(t, x);

        i++;
    }
}

static map<int, int> count{};
void count_nodes_in_level(TREE t, int level = 0) {
    //
    if (t) {
        count[level]++;

        count_nodes_in_level(t->left, level + 1);
        count_nodes_in_level(t->right, level + 1);
    }
}

int main() {
    //
    TREE t{nullptr};

    input(t);

    count_nodes_in_level(t);

    for (auto e : count) {
        printf("So node muc %d cua cay la: %d\n", e.first, e.second);
    }

    return 0;
}
