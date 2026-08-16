/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported define include class
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
void ReverseList(List &l);

// ###INSERT CODE HERE -
node *create_node(int x) {
    //
    node *p{new node};

    p->info = x;

    return p;
}

void nhap(List &l) {
    int x;

    cin >> x;

    while (x) {
        node *t{create_node(x)};

        l.pHead ? l.pTail->pNext = t : l.pHead = t;

        l.pTail = t;

        cin >> x;
    }
}

void xuat(List l) {
    //
    node *p{l.pHead};

    while (p) {
        cout << p->info << ' ';

        p = p->pNext;
    }

    cout << '\n';
}

void add_head(List &l, int x) {
    //
    node *t{create_node(x)};
    l.pTail ? t->pNext = l.pHead : l.pTail = t;

    l.pHead = t;
}

void ReverseList(List &l) {
    //
    List rl;
    CreateList(rl);

    node *p{l.pHead};
    while (p) {
        add_head(rl, p->info);

        p = p->pNext;
    }

    l = rl;
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
        ReverseList(l);
        cout << endl << "Danh sach sau khi dao nguoc la: ";
        xuat(l);
    }
    return 0;
}
