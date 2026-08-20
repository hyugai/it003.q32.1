/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported define include class struct template
###End banned keyword*/
#include <iostream>
using namespace std;
struct node {
    int info;
    node *pNext;
};
struct List {
    node *pHead;
};
void CreateList(List &l) { l.pHead = NULL; }
node *CreateNode(int x);
void AddHead(List &l, node *p);
void enstack(List &l, int x);
void destack(List &l);
bool isEmpty(List l);

int main() {
    List st;
    CreateList(st);

    long long x;
    cin >> x;
    // ###INSERT CODE HERE -

    // 10 - 0, 5 - 1, 2 - 0, 1 - 1
    while (x) {
        enstack(st, x % 2);

        x /= 2;
    }

    if (!isEmpty(st)) {
        node *p{st.pHead};

        while (p) {
            cout << p->info;

            p = p->pNext;
        }
    }

    cout << '\n';
}

node *CreateNode(int x) {
    node *p{new node};

    p->info = x;
    p->pNext = NULL;

    return p;
}

void AddHead(List &l, node *p) {
    l.pHead ? p->pNext = l.pHead : l.pHead = p;

    l.pHead = p;
}

void enstack(List &l, int x) {
    node *t{CreateNode(x)};

    AddHead(l, t);
}

bool isEmpty(List l) { return l.pHead == NULL; }
