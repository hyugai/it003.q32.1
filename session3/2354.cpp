/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported define include
###End banned keyword*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *createNode(int x) {
    Node *node = new Node();
    node->data = x;
    node->next = nullptr;
    return node;
}

// Implement the operation below (reverse by relinking nodes, do NOT build an
// auxiliary array):
//
//   Node* reverseList(Node* head)
//     Reverse the singly linked list and return the new head.
// ###INSERT CODE HERE -
Node *reverseList(Node *head) {
    Node *p{head}, *r_p{nullptr};

    while (p) {
        if (!r_p) {
            r_p = createNode(p->data);
        } else {
            Node *temp_p{createNode(p->data)};

            temp_p->next = r_p;

            r_p = temp_p;
        }

        p = p->next;
    }

    return r_p;
}

void printList(Node *head) {
    bool first = true;
    for (Node *cur = head; cur != nullptr; cur = cur->next) {
        if (!first)
            cout << ' ';
        cout << cur->data;
        first = false;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Node *head = nullptr;
    Node *tail = nullptr;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        Node *node = createNode(v);
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    head = reverseList(head);

    printList(head);

    return 0;
}
