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
void SortIncrease(List &l);

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

void nhap(List &l) {
    int x;
    cin >> x;

    while (x) {
        add_tail(l, x);

        cin >> x;
    }
}

void xuat(List l) {
    node *p{l.pHead};

    while (p) {
        cout << p->info << ' ';

        p = p->pNext;
    }

    cout << '\n';
}

void SortIncrease(List &l) {
    //
    node *p{l.pHead};

    while (p && p != l.pTail) {
        node *q{p->pNext}, *min{p};

        while (q) {
            if (q->info < min->info) {
                min = q;
            }

            q = q->pNext;
        }

        if (min != p) {
            int t{p->info};

            p->info = min->info;

            min->info = t;
        }

        p = p->pNext;
    }
}

int main() {
    List l;
    CreateList(l);
    nhap(l);
    if (l.pHead == NULL)
        cout << "Danh sach rong.";
    else {
        cout << "Danh sach vua nhap la: ";
        xuat(l);
        SortIncrease(l);
        cout << endl << "Danh sach sau khi sap xep la: ";
        xuat(l);
    }
    return 0;
}
