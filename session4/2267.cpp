/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported
define include
###End banned keyword*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(Node *&root, Node *node) {
    if (root == NULL) {
        root = node;
        return;
    }

    if (node->data < root->data) {
        if (root->left == NULL) {
            root->left = node;
            return;
        }
        insertNode(root->left, node);
        return;
    }

    if (root->right == NULL) {
        root->right = node;
        return;
    }
    insertNode(root->right, node);
}

void LNR(Node *root, bool &first) {
    if (root == NULL)
        return;
    LNR(root->left, first);
    if (!first)
        cout << " ";
    cout << root->data;
    first = false;
    LNR(root->right, first);
}

// Returns true if v was found and deleted, false otherwise.
bool deleteNode(Node *&root, int v) {
    // ###INSERT CODE HERE -
    Node *prev_p{nullptr}, *p{root};
    bool is_left;

    while (p) {
        if (v == p->data) {
            //
            if (!prev_p && !p->left && !p->right) {
                root = NULL;

                return true;
            }

            //
            if (!p->left && !p->right) {

                (prev_p->left == p ? prev_p->left = NULL
                                   : prev_p->right = NULL);

                delete p;

                return true;
            }

            // technique -> overload node
            if (p->left && !p->right || !p->left && p->right) {
                *p = (p->left ? *(p->left) : *(p->right));

                return true;
            }

            //
            Node *prev_i{NULL}, *i{p->right};
            while (i) {
                if (!i->left) {
                    p->data = i->data;

                    delete i;

                    (prev_i ? prev_i->left = NULL : p->right = NULL);

                    return true;
                }

                prev_i = i;
                i = i->left;
            }
        }

        //
        prev_p = p;

        p = (v < p->data ? p->left : p->right);
    }

    return false;
}

int main() {
    Node *root = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        insertNode(root, createNode(data));
    }

    int v;
    cin >> v;

    if (!deleteNode(root, v)) {
        cout << "NOT_FOUND" << endl;
    } else if (root == NULL) {
        cout << "EMPTY" << endl;
    } else {
        bool first = true;
        LNR(root, first);
        cout << endl;
    }
    return 0;
}
