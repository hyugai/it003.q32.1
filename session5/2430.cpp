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

static ListNode l;

Node *create_node(int x) {
    //
    Node *p{new Node};

    p->key = x;

    return p;
}

void add_tail(int x) {
    Node *t{create_node(x)};

    l.head ? l.tail->next = t : l.head = t;

    l.tail = t;
}

void input() {
    //
    int x;
    cin >> x;

    while (x) {
        add_tail(x);

        cin >> x;
    }
};

void output() {
    //
    Node *p{l.head};

    if (p) {
        cout << "Danh sach vua nhap la: ";

        while (p) {
            cout << p->key << ' ';

            p = p->next;
        }

        cout << '\n';
    } else {
        cout << "Danh sach rong.\n";
    }
}

int main() {
    //
    input();
    output();

    return 0;
}
