/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported define include
###End banned keyword*/

#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node *next;
};

struct List {
    Node *head;
    Node *tail;
};

Node *createNode(int x) {
    Node *node = new Node();
    node->data = x;
    node->next = nullptr;
    return node;
}

// Implement the following operations on the singly linked list (do NOT use
// std::list):
//   void addHead(List& lst, int x) - insert x at the head
//   void addTail(List& lst, int x) - insert x at the tail
//   void deleteValue(List& lst, int x) - remove the first node equal to x
//
//   (ignore if absent) bool findValue(List& lst, int x) - return true if x
//   is in the list
//
//   void printList(List& lst) - print the list "a b c", or "EMPTY" if it is
//   empty
// ###INSERT CODE HERE -

void addHead(List &lst, int x) {
    //
    // cout << "head\n";
    Node *p{createNode(x)};

    if (!lst.head && !lst.tail) {
        lst.head = lst.tail = p;

    } else {
        p->next = lst.head;

        lst.head = p;
    }
}

void addTail(List &lst, int x) {
    //
    // cout << "tail\n";
    Node *p{createNode(x)};

    if (!lst.head && !lst.tail) {
        lst.head = lst.tail = p;

    } else {
        lst.tail->next = p;

        lst.tail = p;
    }
}

void deleteValue(List &lst, int x) {
    //
    // cout << "delete\n";
    Node *prev_p{lst.head}, *p{lst.head};

    while (p) {
        if (p->data == x) {
            if (p == lst.head) {
                lst.head = p->next;

            } else {
                prev_p->next = p->next;

                delete p;
            }

            return;
        }

        prev_p = p;
        p = p->next;
    }
}

bool findValue(List &lst, int x) {
    //
    // cout << "find\n";
    Node *p{lst.head};

    while (p) {
        if (p->data == x) {
            return true;
        }

        p = p->next;
    }

    return false;
}

void printList(List &lst) {
    // cout << "print\n";
    if (!lst.head) {
        cout << "EMPTY\n";
    } else {
        Node *p{lst.head};

        while (p) {
            cout << p->data << " ";

            p = p->next;
        }

        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    List lst = List{nullptr, nullptr};

    for (int i = 0; i < q; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "ADD_HEAD") {
            int x;
            cin >> x;
            addHead(lst, x);
        } else if (cmd == "ADD_TAIL") {
            int x;
            cin >> x;
            addTail(lst, x);
        } else if (cmd == "DELETE") {
            int x;
            cin >> x;
            deleteValue(lst, x);
        } else if (cmd == "FIND") {
            int x;
            cin >> x;
            cout << (findValue(lst, x) ? "YES" : "NO") << '\n';
        } else {
            printList(lst);
        }
    }

    return 0;
}
