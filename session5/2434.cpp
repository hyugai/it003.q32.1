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
    //
    Node *p{new Node};

    p->key = x;

    return p;
}

void add_tail(ListNode &l, int x) {
    //
    Node *t{create_node(x)};

    l.head ? l.tail->next = t : l.head = t;

    l.tail = t;
}

void add_head(ListNode &l, int x) {
    //
    Node *t{create_node(x)};

    l.tail ? t->next = l.head : l.tail = t;

    l.head = t;
}

void input(ListNode &l, int &y) {
    int x;

    cin >> x;

    while (x) {
        add_tail(l, x);

        cin >> x;
    }

    cin >> y;
}

void reverse_list(ListNode &l) {
    //
    ListNode rl{};

    Node *p{l.head};

    while (p) {
        add_head(rl, p->key);

        p = p->next;
    }

    l = rl;
}

void output(ListNode l) {
    //

    Node *p{l.head};

    if (p) {
        while (p) {
            cout << p->key << ' ';

            p = p->next;
        }

        cout << '\n';
    } else {
        cout << "Danh sach rong.\n";
    }
}

bool delete_node(ListNode &l, int y) {
    //
    Node *prev_p{nullptr}, *p{l.head};

    while (p) {
        if (y == p->key) {
            prev_p ? prev_p->next = p->next : l.head = p->next;

            return true;
        }

        prev_p = p;
        p = p->next;
    }

    return false;
}

int main() {
    //
    ListNode l{};
    int y;

    input(l, y);

    if (l.head) {
        reverse_list(l);

        if (!delete_node(l, y)) {
            cout << "Khong tim thay " << y << " trong danh sach:\n";
        }

        output(l);
    } else {
        cout << "Danh sach rong.\n";
    }

    return 0;
}
