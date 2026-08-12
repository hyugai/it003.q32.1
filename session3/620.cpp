/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported
define include []
###End banned keyword*/
#include <iostream>

using namespace std;

// ###INSERT CODE HERE -
struct node {
    int key;
    node *next{NULL};
};

node *create_new_node(int x) {
    //
    node *p{new node};

    p->key = x;

    return p;
}

void add_head(node *&p, int x) {
    //
    node *t{create_new_node(x)};

    if (p) {
        t->next = p;
    }

    p = t;
}

void input(int &n, node *&p) {
    //
    cin >> n;

    int i{0}, x, count{0};

    while (i < n && count < 10) { // note: 0-9 is 10 elements
        cin >> x;

        if (x >= 90) {
            count++;

            add_head(p, x);
        }

        i++;
    }
}

void output(node *p) {
    while (p) {
        cout << p->key << ' ';

        p = p->next;
    }

    cout << "END\n";
}

int main() {
    //
    int n;
    node *p{NULL};

    input(n, p);
    output(p);

    return 0;
}
