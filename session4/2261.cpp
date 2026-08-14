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

// ###INSERT CODE HERE -
int findMin(Node *p) {
    if (!p->left) {
        return p->data;
    }

    return findMin(p->left);
}

int findMax(Node *p) {
    if (!p->right) {
        return p->data;
    }

    return findMax(p->right);
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

    cout << findMin(root) << " " << findMax(root) << endl;
    return 0;
}
