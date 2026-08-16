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

// ###INSERT CODE HERE -
void insertNode(Node *&root, Node *node) {
    if (!root) {
        root = node;

        return;
    }

    if (root->data == node->data) {
        return;
    }

    if (node->data < root->data) {
        return insertNode(root->left, node);
    }

    if (node->data > root->data) {
        return insertNode(root->right, node);
    }
}

// LNR
void inorder(Node *root) {
    //
    if (root) {
        inorder(root->left);

        cout << root->data << ' ';

        inorder(root->right);
    }
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
    inorder(root);
    cout << "\n";
    return 0;
}
