/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported
define include []
###End banned keyword*/
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

struct List {
    Node *head, *tail;
};

Node *CreateNode(int x) {
    Node *p = new Node;
    if (p == NULL)
        exit(1);
    p->next = NULL;
    p->data = x;
    return p;
}

void CreateList(List &l) { l.head = l.tail = NULL; }

void AddHead(List &l, int x) {
    Node *p = CreateNode(x);
    if (l.head == NULL)
        l.tail = p;
    else
        p->next = l.head;
    l.head = p;
}

void AddTail(List &l, int x) {
    Node *p = CreateNode(x);
    if (l.head == NULL)
        l.head = p;
    else
        l.tail->next = p;
    l.tail = p;
}

// ###INSERT CODE HERE -

void input(int &n, List &l) {
    //
    cin >> n;

    l.head = l.tail = NULL;

    int i{0}, x;

    while (i < n) {
        cin >> x;

        if (!(x % 2)) {
            AddHead(l, x);
        }

        i++;
    }
}

void output(List l) {
    Node *p{l.head};

    while (p) {
        cout << p->data << ' ';

        p = p->next;
    }

    cout << '\n';
}

int main() {
    //
    int n;
    List l;

    input(n, l);
    output(l);

    return 0;
}
