// DMOJ dwite12c1p4

#include <iostream>

#define SIZE 255

using namespace std;

struct node {
    int candy;

    node *left{nullptr}, *right{nullptr};
};
node *new_house(const int candy);
node *new_nonhouse(node *const &left, node *const &right);

void test_node();

int main() {
    //
    test_node();

    return 0;
}

int tree_candy(node *tree) {
    if (!tree->left && !tree->right) { // rule 1: non-house
        return tree->candy;
    }

    return tree_candy(tree->left) + tree_candy(tree->right);
}

node *new_house(const int candy) {
    //
    node *house{new node};
    house->candy = candy;

    return house;
}

node *new_nonhouse(node *const &left, node *const &right) {
    //
    node *nonhouse{new node};

    nonhouse->left = left;
    nonhouse->right = right;

    return nonhouse;
}

void test_node() {
    //
    node *four{new_house(4)}, *nine{new_house(9)}, *B{new_nonhouse(four, nine)},
        *fifteen{new_house(15)}, *C{new_nonhouse(B, fifteen)};

    cout << C->right->candy << endl;
}
