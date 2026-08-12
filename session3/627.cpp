/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported
include []
###End banned keyword*/
#include <iostream>
#include <cmath>

using namespace std;
// ###INSERT CODE HERE -

struct Node {
    double x, y, z;
    Node *next{nullptr};
};

struct ListNode {
    Node *head{nullptr};
    Node *tail{nullptr};
};

void add_tail(ListNode &l) {
    Node *t{new Node};

    cin >> t->x >> t->y >> t->z;

    if (!l.head) {
        l.head = t;
    } else {
        l.tail->next = t;
    }

    l.tail = t;
}

void input_list(int &n, ListNode &l) {
    //
    cin >> n;

    int i{0};

    while (i < n) {
        add_tail(l);

        i++;
    }
}

bool equal_node(Node *lhs, Node *rhs) {
    //
    constexpr double EPS{1e-8};

    int i{0};

    double diff{abs(lhs->x - rhs->x)};
    if (diff > EPS) {
        return false;
    }

    diff = abs(lhs->y - rhs->y);
    if (diff > EPS) {
        return false;
    }

    diff = abs(lhs->z - rhs->z);
    if (diff > EPS) {
        return false;
    }

    return true;
}

void find_point(ListNode l, Node *target) {
    //
    Node *p{l.head};

    int i{0};

    while (p) {
        if (equal_node(target, p)) {
            cout << i << '\n';

            return;
        }

        i++;
        p = p->next;
    }

    cout << "KHONG" << '\n';
}

void run() {
    //
    int n, m;
    ListNode l_a, l_p;

    input_list(n, l_a);
    input_list(m, l_p);

    Node *i{l_p.head};

    while (i) {
        find_point(l_a, i);

        i = i->next;
    }
}

int main() {

    int *a = new int[256];
    int *b = new int[256];
    delete[] a;
    run();
    delete[] b;
}
