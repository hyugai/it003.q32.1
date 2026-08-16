/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported

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

bool firstPrinted = false;
void inorder(Node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    if (firstPrinted)
        cout << ' ';
    firstPrinted = true;
    cout << root->data;
    inorder(root->right);
}

// ###INSERT CODE HERE -

Node *deleteNode(Node *root, int x) {
    //
    Node *prev_p{NULL}, *p{root};

    while (p) {
        if (x == p->data) {
            //
            if (!prev_p && !p->left && !p->right) {
                delete p;

                return NULL;
            }

            //
            if (!p->left && !p->right) {
                (prev_p->left == p ? prev_p->left = NULL
                                   : prev_p->right = NULL);

                delete p;

                return root;
            }

            //
            if (p->left && !p->right || !p->left && p->right) {
                *p = (p->left ? *(p->left) : *(p->right));

                return root;
            }

            //
            Node *prev_i{NULL}, *i{p->right};
            while (i) {
                if (!i->left) {
                    p->data = i->data;

                    // if left-most node right sub-tree and we disconnect, that
                    // right sub-tree will be discarded
                    //
                    // -> solution: overload node instead of deleting it if
                    // right sub-tree is detected
                    if (i->right) {
                        *i = *(i->right);
                    } else {
                        delete i;

                        (prev_i ? prev_i->left = NULL : p->right = NULL);
                    }

                    return root;
                }

                prev_i = i;
                i = i->left;
            }
        }

        prev_p = p;
        p = (x < p->data ? p->left : p->right);
    }

    return root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Node *root = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        insertNode(root, createNode(data));
    }
    int d;
    cin >> d;
    for (int i = 0; i < d; i++) {
        int x;
        cin >> x;
        root = deleteNode(root, x);
    }
    inorder(root);
    cout << "\n";
    return 0;
}
