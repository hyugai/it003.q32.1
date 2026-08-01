// DMOJ dwite12c1p4

#include <iostream>

#define SIZE 255

using namespace std;

struct node {
    int candy;

    node *left{nullptr}, *right{nullptr};
};

void delete_tree(node *tree);

int main() {
    //
    char *line{nullptr};
    node *tree{nullptr};

    //

    //
    delete[] line;
    delete_tree(tree);

    return 0;
}

void input(char *&line, node *&tree) {
    //
    line = new char[SIZE + 1];

    cin.getline(line, SIZE);

    int pos = 0;
}

node *read_tree(char *const &line, int *pos) {
    // base case
    node *tree = new node;

    if (line[*pos] != '(') {

        int candy{0}, digit{line[*pos]};

        candy += digit - '0';

        (*pos)++;

        digit = line[*pos];

        if (digit >= '0' && digit <= '9') {
            candy = (candy * 10) + (digit - '0');
        }

        tree->candy = candy;

    } else {
        (*pos)++;
        tree->left = read_tree(line, pos);

        (*pos)++; // skip blank
        tree->right = read_tree(line, pos);

        (*pos)++;
    }

    return tree;
}

void delete_tree(node *tree) {
    // base case
    if (!tree) {
        return;
    }

    //
    delete_tree(tree->left);
    delete_tree(tree->right);

    delete tree;
}
