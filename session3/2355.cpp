/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported
define include
###End banned keyword*/

#include <iostream>
#include <string>
using namespace std;

// Implement a stack of characters yourself (array or linked list, do NOT use
// std::stack) and use it to write the function below:
//   bool isBalanced(const string& s)
//     Return true if the bracket string s is valid (every opener is closed by
//     the matching closer in the correct nesting order), otherwise false.
// ###INSERT CODE HERE -

struct Node {
    char bracket;
    Node *next{nullptr};
};

struct ListNode {
    Node *head{nullptr};
    Node *tail{nullptr};
};

Node *create_node(char c) {
    //
    Node *p{new Node};

    p->bracket = c;

    return p;
}

void add_head(ListNode &l, char c) {
    Node *t{create_node(c)};

    if (!l.head) {
        l.tail = t;
    } else {
        t->next = l.head;
    }

    l.head = t;
}

void pop_stack(ListNode &l) {
    if (l.head) {
        Node *t{l.head->next};

        if (l.head == l.tail) {
            l.tail = nullptr;
        }

        delete l.head;

        l.head = t;
    }
}

void print_list(Node *p) {
    while (p) {
        cout << p->bracket << ' ';

        p = p->next;
    }

    cout << endl;
}

bool isBalanced(const string &s) {
    //
    ListNode my_stack;

    for (auto c : s) {
        // cout << my_stack.head << endl;
        if (!my_stack.head) {
            add_head(my_stack, c);
            // cout << 1 << endl;

            continue;
        }

        if (my_stack.head->bracket == '(' && c == ')' ||
            my_stack.head->bracket == '[' && c == ']' ||
            my_stack.head->bracket == '{' && c == '}') {

            pop_stack(my_stack);

            continue;
        }

        add_head(my_stack, c);
    }

    return (my_stack.head == nullptr ? true : false);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    cout << (isBalanced(s) ? "YES" : "NO") << '\n';

    return 0;
}
