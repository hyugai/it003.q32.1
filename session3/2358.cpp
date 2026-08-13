/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported define include
###End banned keyword*/

#include <iostream>
#include <string>
using namespace std;

// Implement a queue of document names yourself (array or linked list, FIFO,
// do NOT use std::queue) providing the following operations:
//   void enqueue(const string& name) - add a document name to the back
//   bool emptyQueue()                - return true if the queue is empty
//   string dequeue()                 - remove and return the front document
//   name (queue is non-empty)
// ###INSERT CODE HERE -

struct Node {
    string key;
    Node *next{nullptr};
};

struct ListNode {
    Node *head{nullptr};
    Node *tail{nullptr};
};

static ListNode my_queue;

Node *create_node(const string &name) {
    //
    Node *p{new Node};

    p->key = name;

    return p;
}

// add tail
void enqueue(const string &name) {
    Node *t{create_node(name)};

    if (!my_queue.head) {
        my_queue.head = t;
    } else {
        my_queue.tail->next = t;
    }

    my_queue.tail = t;
}

bool emptyQueue() { return (my_queue.head == nullptr ? true : false); }

string dequeue() {
    //
    string x{my_queue.head->key};
    Node *t{my_queue.head->next};

    if (my_queue.head == my_queue.tail) {
        my_queue.tail = nullptr;
    }

    delete my_queue.head;

    my_queue.head = t;

    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "ADD") {
            string name;
            cin >> name;
            enqueue(name);
        } else {
            if (emptyQueue())
                cout << "NO DOCUMENT\n";
            else
                cout << dequeue() << '\n';
        }
    }

    return 0;
}
