/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported define include
###End banned keyword*/

#include <iostream>
using namespace std;

// Implement a stack of int yourself (array or linked list, do NOT use
// std::stack) and use it to write the function below:
//   void printBinary(int n)
//     Print the binary representation of n (no leading zeros), followed by a
//     newline. Hint: push n % 2, then n /= 2; finally pop the bits to print
//     them (LIFO).
// ###INSERT CODE HERE -
struct Node {
    int d;
    Node *next{nullptr};
};

struct ListNode {
    Node *head{nullptr};
    Node *tail{nullptr};
};

Node *create_node(int x) {
    //
    Node *p{new Node};

    p->d = x;

    return p;
}

void add_head(ListNode &l, int x) {
    Node *t{create_node(x)};

    if (!l.tail) {
        l.tail = t;
    }

    t->next = l.head;

    l.head = t;
}

void print_list(Node *p) {
    while (p) {
        cout << p->d;

        p = p->next;
    }

    cout << '\n';
}

void printBinary(int n) {
    //
    static ListNode my_stack;

    if (n == 0) {
        print_list(my_stack.head);

        return;
    }

    add_head(my_stack, n % 2);

    return printBinary(n / 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    printBinary(n);

    return 0;
}
