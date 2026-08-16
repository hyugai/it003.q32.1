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

// ###INSERT CODE HERE -
int findMax(Node *root) {
    //
    int max{root->data};

    Node *p{root->right};

    while (p) {
        if (p->data > max) {
            max = p->data;
        }

        p = p->right;
    }

    return max;
}
int findMin(Node *root) {
    //
    int min{root->data};

    Node *p{root->left};

    while (p) {
        if (p->data < min) {
            min = p->data;
        }

        p = p->left;
    }

    return min;
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
    cout << findMin(root) << ' ' << findMax(root) << "\n";
    return 0;
}
