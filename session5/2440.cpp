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
    int key, count{0};
    Node *next{nullptr};
};

struct ListNode {
    Node *head;
    Node *tail;
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

static string s{""};

void input(ListNode &l) {
    int x;

    cin >> x;

    while (x) {
        add_head(l, x);

        cin >> x;
    }
}

void output(ListNode l) {
    Node *p{l.head};

    while (p) {
        s += to_string(p->key) + ' ';

        p = p->next;
    }

    s += '\n';
}

static int max_count{0};
void count_element(ListNode &l) {
    //
    Node *p{l.head};

    while (p) {
        Node *q{p};

        while (q) {
            if (q->key == p->key) {
                p->count++;

                if (p->count > max_count) {
                    max_count = p->count;
                }
            }

            q = q->next;
        }

        p = p->next;
    }
}

void output_count(ListNode l) {
    //
    Node *p{l.head};

    while (p) {
        if (p->count == max_count) {
            s += to_string(p->key) + ": " + to_string(max_count) + '\n';
        }

        p = p->next;
    }
}

int main() {
    //
    ListNode l{};

    input(l);

    if (l.head) {
        output(l);

        count_element(l), output_count(l); // TLE

        cout << s;
    } else {
        cout << "Danh sach rong.\n";
    }

    return 0;
}
