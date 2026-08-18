/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported
define include class
[]
template
###End banned keyword*/

#include <iostream>
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

void input(ListNode &l) {
    int x;

    cin >> x;

    while (x) {
        add_tail(l, x);

        cin >> x;
    }
}

void output(ListNode l) {
    // check empty list at main already
    Node *p{l.head};

    while (p) {
        cout << p->key << ' ';

        p = p->next;
    }

    cout << '\n';
}

bool check_order(ListNode l) {
    //
    bool is_increasing{false}, is_decreasing{false};

    Node *p{l.head};

    while (p && p != l.tail) {
        if (p->key < p->next->key) {
            is_increasing = true;
        }

        if (p->key > p->next->key) {
            is_decreasing = true;
        }

        if (is_increasing && is_decreasing) {
            return false;
        }

        p = p->next;
    }

    return is_increasing && !is_decreasing ? true : false;
}

void insert_node(ListNode &l, Node *prev_p, Node *p, int x) {
    // head
    if (!prev_p) {
        add_head(l, x);
    }

    // tail
    if (!p) {
        add_tail(l, x);
    }

    // mid
    Node *t{create_node(x)};

    prev_p->next = t;

    t->next = p;
}

void insert_x(ListNode &l, int x) {
    // insert after
    Node *prev_p{nullptr}, *p{l.head};

    while (p) {
        if (x < p->key) {
            break;
        }

        prev_p = p;
        p = p->next;
    }

    insert_node(l, prev_p, p, x);
}

int main() {
    //
    ListNode l;

    input(l);

    if (l.head) {
        int x;
        cin >> x;

        cout << "Danh sach vua nhap la: ", output(l);

        if (check_order(l)) {
            cout << "Danh sach sau khi chen so " << x << " la: ",
                insert_x(l, x), output(l);
        }
    }

    return 0;
}
