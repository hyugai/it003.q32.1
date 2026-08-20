/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported define include class struct template
###End banned keyword*/
#include <string>
#include <iostream>
using namespace std;
struct node {
    char info;
    node *pNext;
};
struct List {
    node *pHead;
    node *pTail;
};
void CreateList(List &l);
node *CreateNode(char x);
void AddTail(List &l, node *p);
void Xuat(List l);
void enqueue(List &l, char x);
int dequeue(List &l);
bool isEmpty(List l);

int main() {
    char c;
    cin >> c;

    string s = "";
    cin >> s;

    List queue;
    CreateList(queue);

    // ###INSERT CODE HERE -
    if (s.length() == 0) {
        cout << "Chuoi rong.\n";

        return 0;
    }

    for (auto x : s) {
        if (x == c) {
            if (!isEmpty(queue)) {
                cout << (char)dequeue(queue);
            }

        } else {
            enqueue(queue, x);
        }
    }
    cout << '\n';

    Xuat(queue);

    //
    return 0;
}

void CreateList(List &l) {
    l.pHead = nullptr;
    l.pTail = nullptr;
}

node *CreateNode(char x) {
    node *p{new node};

    p->info = x;
    p->pNext = nullptr;

    return p;
}

void AddTail(List &l, node *p) {
    l.pHead ? l.pTail->pNext = p : l.pHead = p;

    l.pTail = p;
}

void Xuat(List l) {
    if (isEmpty(l)) {
        cout << "Hang doi rong.\n";
    } else {
        cout << "Cac gia tri co trong hang doi la: ";

        node *p{l.pHead};

        while (p) {
            cout << p->info;

            p = p->pNext;
        }

        cout << '\n';
    }
}

void enqueue(List &l, char x) {
    node *t{CreateNode(x)};

    AddTail(l, t);
}

int dequeue(List &l) {
    int x{l.pHead->info};

    l.pHead == l.pTail ? l.pHead = l.pTail = nullptr : l.pHead = l.pHead->pNext;

    return x;
}

bool isEmpty(List l) { return l.pHead == nullptr; }
