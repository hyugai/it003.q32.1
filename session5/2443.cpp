/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported define include class
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

// push
void add_head(ListNode &l, int x) {
    Node *t{create_node(x)};

    l.tail ? t->next = l.head : l.tail = t;

    l.head = t;
}

// pop
void remove_head(ListNode &l) {
    if (!l.head) {
        cout << "Stack rong.\n";

        return;
    }

    l.head == l.tail ? l.head = l.tail = nullptr : l.head = l.head->next;
}

void run(ListNode &l, int target) {
    int x;
    cin >> x;

    while (x) {
        x == target ? remove_head(l) : add_head(l, x);

        cin >> x;
    }
}

void output(ListNode l) {
    if (l.head) {
        cout << "Cac gia tri co trong stack la: ";

        Node *p{l.head};

        while (p) {
            cout << p->key << ' ';

            p = p->next;
        }

        cout << '\n';
    } else {
        cout << "Stack rong.\n";
    }
}

int main() {
    ListNode l{};

    int x;
    cin >> x;

    run(l, x);

    output(l);

    return 0;
}
