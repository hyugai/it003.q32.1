/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported
define include class
[]
template
###End banned keyword*/

#include <iostream>
#include <math.h>
using namespace std;

// ###INSERT CODE HERE -
struct Node {
    int key;
    Node *next;
};

struct ListNode {
    Node *head{nullptr};
    Node *tail{nullptr};
};

static ListNode l{};
static int prime_count{0}, idx{0};

Node *create_node(int x) {
    //
    Node *p{new Node};

    p->key = x;

    return p;
}

void add_tail(int x) {
    //
    Node *t{create_node(x)};

    l.head ? l.tail->next = t : l.head = t;

    l.tail = t;
}

bool is_prime(int x) {
    //
    if (x <= 1) {
        return false;
    }

    int i{2};

    while (i * i <= x) {
        if (!(x % i)) {
            return false;
        }

        i++;
    }

    return true;
}

void input() {
    int x;

    cin >> x;

    while (x) {
        add_tail(x), idx++;

        // odd index
        if (idx % 2) {
            prime_count += is_prime(x);
        }

        cin >> x;
    }
}

void output() {
    //
    Node *p{l.head};

    if (p) {
        cout << "Danh sach vua nhap la: ";

        while (p) {
            cout << p->key << ' ';

            p = p->next;
        }

        cout << "\nDanh sach co " << prime_count
             << " so nguyen to o vi tri le.\n";

    } else {
        cout << "Danh sach rong.\n";
    }
}

int main() {
    //
    input();
    output();

    return 0;
}
