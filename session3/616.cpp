/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported
define include []
###End banned keyword*/
#include <iostream>

using namespace std;

// ###INSERT CODE HERE -
struct node {
    int key;
    node *next;
};

node *create_node(int x) {
    //
    node *p{new node};

    p->key = x;
    p->next = nullptr;

    return p;
}

void input(int &n, node *&head) {
    //
    cin >> n;

    node *t, *p{head};
    int i{0}, x;

    while (i < n) {
        cin >> x;

        t = create_node(x);

        if (!head) {
            head = t;
        } else {
            p->next = t;
        }

        p = t;
        i++;
    }
}

void print_linked_list(node *p) {
    while (p) {
        cout << p->key << ' ';

        p = p->next;
    }
    cout << '\n';
}

void create_linked_list_even(int n, node *&head, node *p, int &count) {
    if (n == 0) {
        return;
    }

    int x;
    cin >> x;

    if (!(x % 2)) {
        count++;

        node *t{create_node(x)};

        if (!head) {
            head = p = t;

        } else {
            p->next = t;

            p = t;
        }
    }

    return create_linked_list_even(n - 1, head, p, count);
}

void get_mid(node *p, int mid) {
    if (mid == 1) {
        cout << p->key << '\n';
        return;
    }

    p = p->next;

    return get_mid(p, mid - 1);
}

int main() {
    //
    int n;

    cin >> n;

    int count{0};
    node *head{nullptr}, *p{nullptr};

    create_linked_list_even(n, head, p, count);

    int mid{(count % 2 ? count / 2 + 1 : count / 2)};

    get_mid(head, mid);

    return 0;
}
