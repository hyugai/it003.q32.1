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

void input(ListNode &l) {
    int x;
    cin >> x;

    while (x) {
        add_tail(l, x);

        cin >> x;
    }
}

bool is_prime(int x) {
    if (x < 2) {
        return false;
    }

    int i{2};
    while (i * i <= x) {
        if (!(x % 2)) {
            return false;
        }

        i++;
    }

    return true;
}

void output_even_idxes(ListNode l) {
    //
    int idx{1};
    Node *p{l.head};
    string s{""};

    while (p) {
        if (idx % 2 == 0 && is_prime(p->key)) {
            cout << p->key << ' ';
        }

        p = p->next;
        idx++;
    }

    cout << '\n';
}

int main() {
    //
    ListNode l{};

    input(l);

    output_even_idxes(l);

    return 0;
}
