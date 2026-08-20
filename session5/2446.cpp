/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported define include class template
###End banned keyword*/
#include <iostream>
#include <string.h>
using namespace std;
// ###INSERT CODE HERE -

struct Node {
    int key;
    Node *next{nullptr};
};

struct ListNode {
    Node *head{nullptr};
    Node *tail{nullptr};
};

Node *create_node(int x) {
    Node *p{new Node};

    p->key = x;

    return p;
}

void add_head(ListNode &l, int x) {
    Node *t{create_node(x)};

    l.tail ? t->next = l.head : l.tail = t;

    l.head = t;
}

int main() {
    //
    int a, b;
    cin >> a >> b;

    if (!a || !b) {
        cout << 0;

        return 0;
    }

    ListNode st{};
    int c{0}, d;

    while (a) {
        d = (a % 10) * b + c;

        d > 9 ? c = d / 10, add_head(st, d % 10) : add_head(st, d);

        a /= 10;
    }

    if (c) {
        add_head(st, c);
    }

    Node *p{st.head};
    while (p) {
        cout << p->key;

        p = p->next;
    }

    cout << '\n';

    return 0;
}
