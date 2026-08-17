/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported define
include class
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
    //
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
    //
    int x;

    cin >> x;

    while (x) {
        add_tail(l, x);

        cin >> x;
    }
}

void output(List l) {
    node *p{l.pHead};

    int x;

    while (p) {
        cout << p->info << ' ';

        p = p->pNext;
    }

    cout << '\n';
}

void sort_list(List &l) {
    node *p{l.pHead};

    while (p && p != l.pTail) {
        node *q{p->pNext}, *min{p};

        while (q) {
            if (q->info < min->info) {
                min = q;
            }

            /*
             * unexpected behavior if swap is performed here (in each iteration
             * of the inner loop)
             * */
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

void merge_list(List l1, List l2, List &l) {
    //
    node *p{l1.pHead}, *q{l2.pHead};

    while (p && q) {
        if (p->info < q->info) {
            add_tail(l, p->info);

            p = p->pNext;
        } else {
            add_tail(l, q->info);

            q = q->pNext;
        }
    }

    while (p) {
        add_tail(l, p->info);

        p = p->pNext;
    }

    while (q) {
        add_tail(l, q->info);

        q = q->pNext;
    }
}

int main() {
    //
    List l1, l2, l;

    CreateList(l1), CreateList(l2), CreateList(l);

    input(l1), input(l2);

    if (l1.pHead) {
        cout << "Danh sach l1 la: ";

        output(l1);
    } else {
        cout << "Danh sach l1 rong.\n";
    }

    if (l2.pHead) {
        cout << "Danh sach l2 la: ";

        output(l2);
    } else {
        cout << "Danh sach l2 rong.\n";
    }

    if (l1.pHead && l2.pHead) {
        cout << "Danh sach l1 sau khi sap xep la: ", sort_list(l1), output(l1);

        cout << "Danh sach l2 sau khi sap xep la: ", sort_list(l2), output(l2);

        cout << "Ket qua tron l1 voi l2 la: ", merge_list(l1, l2, l), output(l);
    } else {
        cout << "Khong tron duoc.\n";
    }

    return 0;
}
