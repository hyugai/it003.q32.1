/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported define include
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

// Implement the two functions below. For each, set out_found = true and
// out_val = value if it exists; otherwise set out_found = false.
//   predecessor(root, x, out_found, out_val) -> largest value strictly less
//   than x successor(root, x, out_found, out_val)   -> smallest value strictly
//   greater than x
// ###INSERT CODE HERE -

/*
 * given test case can be misleading since its target is at leaf
 *
 * -> question: how about if target is node (not leaf)
 *  e.g:
 *  7
 *  50 30 70 20 40 60 80
 *  70 -> target is node
 * */
void predecessor(Node *root, int x, bool &pf, int &pv) {
    //
    pf = false;

    while (root) {
        // node x (turn right)
        if (x > root->data) {
            if (!pf) {
                pv = root->data;

                pf = true;

            } else if (root->data > pv) {
                pv = root->data;
            }

            root = root->right;

            continue;
        }

        // x node
        if (x <= root->data) {
            root = root->left;

            continue;
        }
    }
}

void successor(Node *root, int x, bool &sf, int &sv) {
    //
    sf = false;

    while (root) {
        if (x < root->data) {
            if (!sf) {
                sv = root->data;

                sf = true;

            } else if (root->data < sv) {

                sv = root->data;
            }

            root = root->left;

            continue;
        }

        if (x >= root->data) {
            root = root->right;

            continue;
        }
    }
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

    int x;
    cin >> x;

    bool pf, sf;
    int pv, sv;
    predecessor(root, x, pf, pv);
    successor(root, x, sf, sv);

    cout << "Pred: ";
    if (pf)
        cout << pv;
    else
        cout << "NONE";
    cout << "\nSucc: ";
    if (sf)
        cout << sv;
    else
        cout << "NONE";
    cout << "\n";
    return 0;
}
