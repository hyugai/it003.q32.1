/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported define include
###End banned keyword*/

#include <iostream>
#include <string>
using namespace std;

// Implement an integer queue yourself (circular array or linked list, FIFO,
// do NOT use std::queue) providing the following operations:
//   void enqueue(int x)   - add x to the back
//
//   bool emptyQueue()     - return true if the queue is empty
//
//   int  frontValue()     - return the front value (the queue is non-empty)
//
//   int  dequeue()        - remove and return the front value (the queue is
//   non-empty)
//
//   int  sizeQueue()      - return the number of elements currently in the
//   queue
// ###INSERT CODE HERE -
struct Node {
    int key;
    Node *next{nullptr};
};

struct ListNode {
    Node *head{nullptr};
    Node *tail{nullptr};
};

static ListNode my_queue;

Node *create_node(int x) {
    Node *p{new Node};

    p->key = x;

    return p;
}

void enqueue(int x) {
    Node *t{create_node(x)};

    if (!my_queue.tail) {
        my_queue.head = t;
    } else {
        my_queue.tail->next = t;
    }

    // cout << 1 << endl;
    my_queue.tail = t;
}

bool emptyQueue() { return (my_queue.head == nullptr ? true : false); }

int frontValue() {
    //
    return my_queue.head->key;
}

int dequeue() {
    //
    Node *t{my_queue.head->next};

    int x{my_queue.head->key};

    // bug: if queue has only 1 element, set tail to NULL to avoid dangling
    // pointer
    if (my_queue.tail == my_queue.head) {
        my_queue.tail = nullptr;
    }

    delete my_queue.head;

    my_queue.head = t;

    return x;
}

int sizeQueue() {
    int count{0};

    Node *p = my_queue.head;

    while (p) {
        count++;

        p = p->next;
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "ENQUEUE") {
            int x;
            cin >> x;
            enqueue(x);
        } else if (cmd == "DEQUEUE") {
            if (emptyQueue())
                cout << "EMPTY\n";
            else
                cout << dequeue() << '\n';
        } else if (cmd == "FRONT") {
            if (emptyQueue())
                cout << "EMPTY\n";
            else
                cout << frontValue() << '\n';
        } else {
            cout << sizeQueue() << '\n';
        }
    }

    return 0;
}
