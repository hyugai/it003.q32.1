/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported
define
include
class
[
]
template

###End banned keyword*/

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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

void add_tail(ListNode &l, int x) {
    Node *t{create_node(x)};

    l.head ? l.tail->next = t : l.head = t;

    l.tail = t;
}

void add_head(ListNode &l, int x) {
    Node *t{create_node(x)};

    l.tail ? t->next = l.head : l.tail = t;

    l.head = t;
}

void input(ListNode &l, int &k) {
    int x;
    cin >> x;

    while (x) {
        add_tail(l, x);

        cin >> x;
    }

    cin >> k;
}

void divide_and_merge(ListNode &l, ListNode &l1, ListNode &l2, int k) {
    Node *p{l.head};

    while (p) {
        p->key % k ? add_head(l2, p->key) : add_tail(l1, p->key);

        p = p->next;
    }

    Node *i{l1.head}, *j{l2.head};

    while (i) {
        cout << i->key << ' ';

        i = i->next;
    }

    while (j) {
        cout << j->key << ' ';

        j = j->next;
    }

    cout << '\n';
}

int main() {
    ListNode l, l1, l2;
    int k;

    input(l, k);

    divide_and_merge(l, l1, l2, k);

    return 0;
}
