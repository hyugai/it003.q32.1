/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported
define
include
class
[]
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

void count_element(ListNode &l, int x) {
    //
    Node *p{l.head};

    while (p) {
        if (x == p->key) {
            p->count++;

            return;
        }

        p = p->next;
    }

    add_tail(l, x);

    l.tail->count++;
}

static string s{"Danh sach vua nhap la: "};

void input(ListNode &l) {
    int x;

    cin >> x;

    while (x) {
        s += to_string(x) + ' ';

        count_element(l, x); // cause TLE

        cin >> x;
    }
}

void output(ListNode l) {
    // check if list is empty in main
    Node *p{l.head};

    while (p) {
        s += to_string(p->key) + ' ';

        p = p->next;
    }
}

void output_count(ListNode l) {
    Node *p{l.head};

    while (p) {
        s += to_string(p->key) + ": " + to_string(p->count) + '\n';

        p = p->next;
    }
}

int main() {
    //
    ListNode l{};

    input(l);

    if (l.head) {
        s += "\nSo lan xuat hien cua tung phan tu trong danh sach la:\n",
            output_count(l);

        cout << s;
    } else {
        cout << "Danh sach rong.\n";
    }

    return 0;
}
