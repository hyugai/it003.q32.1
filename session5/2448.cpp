/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported
include
class template
[
]
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
    Node *t{create_node(x)};

    l.head ? l.tail->next = t : l.head = t;

    l.tail = t;
}

void input(ListNode &l) {
    int x;

    while (cin >> x && x) {
        add_tail(l, x);
    }
}

static string s{""};
void linear_search(ListNode l, int x) {
    // check empty list at main
    Node *p{l.head};

    while (p) {
        if (x == p->key) {
            s += "YES\n";

            return;
        }

        p = p->next;
    }

    s += "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ListNode l{};

    input(l);

    int x;
    while (cin >> x && x) {
        linear_search(l, x);
    }

    cout << s;

    return 0;
}
