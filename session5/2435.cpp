/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported
define include class
[]
template
###End banned keyword*/

#include <iostream>
using namespace std;
struct node {
    int info;
    node *pNext;
};
struct List {
    node *pHead;
    node *pTail;
};
void CreateList(List &l) {
    l.pHead = NULL;
    l.pTail = NULL;
}

// ###INSERT CODE HERE -
node *create_node(int x) {
    node *p{new node};

    p->info = x;
    p->pNext = NULL;

    return p;
}

void add_tail(List &l, int x) {
    //
    node *t{create_node(x)};

    l.pHead ? l.pTail->pNext = t : l.pHead = t;

    l.pTail = t;
}

void input(List &l) {
    int x;
    cin >> x;

    while (x) {
        add_tail(l, x);

        cin >> x;
    }
}

void check_order(List l) {
    //
    node *p{l.pHead};

    bool is_increasing{false}, is_decreasing{false};

    while (p && p != l.pTail) {
        if (p->info < p->pNext->info) {
            is_increasing = true;
        }

        if (p->info > p->pNext->info) {
            is_decreasing = true;
        }

        if (is_increasing && is_decreasing) {
            cout << "Danh sach khong tang cung khong giam.\n";

            return;
        }

        p = p->pNext;
    }

    if (!is_increasing && !is_decreasing) {
        cout << "Danh sach khong tang cung khong giam.\n";
    } else {
        cout << "Danh sach " << (is_increasing ? "tang" : "giam") << ".\n";
    }
}

void output(List l) {
    //
    node *p{l.pHead};

    if (p) {
        cout << "Danh sach vua nhap la: ";

        while (p) {
            cout << p->info << ' ';

            p = p->pNext;
        }

        cout << '\n';
        check_order(l);
    } else {
        cout << "Danh sach rong.\n";
    }
}

int main() {
    List l;
    CreateList(l);

    input(l);
    output(l);
}
