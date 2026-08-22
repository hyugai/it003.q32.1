/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported
include
class template
[
]
###End banned keyword*/

#include <iostream>

using namespace std;

// ###INSERT CODE HERE -
struct Node {
    int key, level{1};
    Node *left{nullptr}, *right{nullptr};
};

typedef Node *TREE;

Node *create_node(int x) {
    Node *p{new Node};

    p->key = x;

    return p;
}

void add_node(TREE &root, int x) {
    if (!root) {
        root = create_node(x);

        return;
    }

    if (x == root->key) {
        return;
    }

    x < root->key ? add_node(root->left, x) : add_node(root->right, x);
}

void input(TREE &root) {
    int x;

    while (cin >> x && x) {
        add_node(root, x);
    }
}

struct LLNode {
    Node *key;
    LLNode *next{nullptr};
};

struct ListNode {
    LLNode *head{nullptr};
    LLNode *tail{nullptr};
};

LLNode *create_llnode(Node *x) {
    LLNode *p{new LLNode};

    p->key = x;

    return p;
}

void add_tail(ListNode &l, Node *x) {
    LLNode *t{create_llnode(x)};

    l.head ? l.tail->next = t : l.head = t;

    l.tail = t;
}

Node *remove_head(ListNode &l) {
    if (!l.head) {
        return nullptr;
    }

    Node *p{l.head->key};

    l.head != l.tail ? l.head = l.head->next : l.head = l.tail = nullptr;

    return p;
}

bool is_queue_empty(ListNode l) { return l.head == nullptr; }

static string s{""};
void output(TREE root) {
    //
    int current_lv{0};
    ListNode q{};

    add_tail(q, root);

    while (!is_queue_empty(q)) {
        Node *p{remove_head(q)};

        if (current_lv != p->level) {
            s += "\nDeep " + to_string(p->level) + ": " + to_string(p->key) +
                 " ";

            current_lv = p->level;

        } else {
            s += to_string(p->key) + " ";
        }

        if (p->left) {
            add_tail(q, p->left);
            q.tail->key->level += p->level;
        }

        if (p->right) {
            add_tail(q, p->right);
            q.tail->key->level += p->level;
        }
    }
}

void LNR(TREE root) {
    if (root) {
        LNR(root->left);
        cout << root->key << ' ';
        LNR(root->right);
    }
}

int main() {
    //
    TREE root{nullptr};

    input(root);

    output(root);

    cout << s.erase(0, 1) + '\n';

    return 0;
}
