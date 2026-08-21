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
    int key;
    Node *left{nullptr}, *right{nullptr};
};

typedef Node *TREE;

Node *create_node(int x) {
    Node *p{new Node};

    p->key = x;

    return p;
}

void add_node(TREE &t, int x) {
    if (!t) {
        t = create_node(x);

        return;
    }

    if (x == t->key) {
        return;
    }

    x < t->key ? add_node(t->left, x) : add_node(t->right, x);
}

void input(TREE &t, int &n) {
    int x;

    while (cin >> x && x) {
        add_node(t, x);
    }

    cin >> n;
}

Node *delete_node(TREE root, int x) {
    //
    Node *prev_p{nullptr}, *p{root};

    while (p) {
        if (x == p->key) {
            // cout << p->key << ' ';

            // tree has only 1 node -> empty tree
            if (!prev_p && !p->left && !p->right) {
                // cout << 1 << endl;

                return nullptr;
            }

            // leaf -> delete
            if (!p->left && !p->right) {
                // cout << 2 << endl;

                prev_p->left == p ? prev_p->left = nullptr
                                  : prev_p->right = nullptr;

                return root;
            }

            // level-1 node -> overload
            if (!p->left && p->right || p->left && !p->right) {
                //   cout << 3 << endl;

                *p = p->left ? *(p->left) : *(p->right);

                return root;
            }

            // level-2 node -> find -> swap key -> delete/overload
            // -> deleted node is either leftmost node or right sub-tree
            // -> overload if deleted node has right child

            // cout << 4 << endl;

            Node *prev_i{nullptr}, *i{p->right};
            while (i) {
                if (!i->left) {
                    p->key = i->key;

                    if (i->right) {
                        *i = *(i->right);
                    } else {
                        prev_i ? prev_i->left = nullptr : p->right = nullptr;
                    }

                    return root;
                }

                prev_i = i;
                i = i->left;
            }
        }

        prev_p = p;
        x < p->key ? p = p->left : p = p->right;
    }

    return root;
}

bool is_prime(int n) {
    if (n < 2) {
        return false;
    }

    int i{2};
    while (i * i <= n) {
        if (n % i == 0) {
            return false;
        }

        i++;
    }

    return true;
}

struct LLNode {
    int key;
    LLNode *next{nullptr};
};

struct ListNode {
    LLNode *head{nullptr};
    LLNode *tail{nullptr};
};

LLNode *create_llnode(int x) {
    LLNode *p{new LLNode};

    p->key = x;

    return p;
}

void add_tail(ListNode &l, int x) {
    LLNode *t{create_llnode(x)};

    l.head ? l.tail->next = t : l.head = t;

    l.tail = t;
}

void find_prime(ListNode &l, TREE t, int &n) {
    if (n && t) {
        find_prime(l, t->left, n);

        if (n && is_prime(t->key)) {
            // cout << n << ':' << t->key << ' ';
            add_tail(l, t->key);
            n--;
        }

        find_prime(l, t->right, n);
    }
}

static string s{""};
void output(TREE t) {
    if (t) {
        output(t->left);

        s += to_string(t->key) + ' ';

        output(t->right);
    }
}

int main() {
    //
    TREE root{nullptr};
    int n;

    input(root, n);

    ListNode l{};
    find_prime(l, root, n);

    LLNode *p{l.head};
    while (p) {
        root = delete_node(root, p->key);

        p = p->next;
    }

    if (root) {
        output(root);

        cout << s << '\n';
    } else {
        cout << "Not found tree!\n";
    }

    return 0;
}
