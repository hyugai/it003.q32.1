#include <cstddef>
#include <iostream>

using namespace std;

struct Node {
    int key;
    Node *next;
};

struct List {
    Node *head;
    Node *tail;
};

/**/
void create_list(List &l);
/**/
Node *create_node(int x);
/**/
Node *linear_search(const List &l, const int x);
/**/
void traverse_list_by_list(const List &l);
/**/
void insert_at_head(List &l, Node *&p);
/**/
void insert_at_tail(List &l, Node *&p);
/**/
void remove_head_node(List &l);
/**/
bool is_list_empty(const List &l);
/**/
int sum_list(const List &l);
/**/
int find_max_value(const List &l);

int main() {
    //
    return 0;
}

int find_max_value(const List &l) {
    //
    Node *p{l.head};

    if (!p) {
        return -1;
    }
    int max{p->key};

    while (p) {
        max = (p->key > max ? p->key : max);

        p = p->next;
    }

    return max;
}

int sum_list(const List &l) {
    int sum{0};

    Node *p{l.head};

    while (p) {
        sum += p->key;

        p = p->next;
    }

    return sum;
}

bool is_list_empty(const List &l) {
    if (!l.head) {
        return true;
    }

    return false;
}

void remove_head_node(List &l) {
    //
    Node *p{l.head->next};

    delete l.head;

    l.head = p;

    // list becomes empty
    if (!l.head) {
        l.tail = l.head;
    }
}

Node *linear_search(const List &l, const int x) {
    //
    Node *p{l.head};

    while (p) {
        if (p->key == x) {
            return p;
        }

        p = p->next;
    }

    return NULL;
}

void traverse_list_by_list(const List &l) {
    //
    Node *p{l.head};

    while (p) {
        cout << p->key;

        p = p->next;
    }
}

void insert_at_tail(List &l, Node *&p) {
    // base case -> empty list
    if (!l.head) {
        l.head = l.tail = p;
    }

    l.tail->next = p;
    l.tail = p;
}

void insert_at_head(List &l, Node *&p) {
    // base case -> empty list
    if (!l.head) {
        l.head = l.tail = p;
    }

    p->next = l.head;
    l.head = p;
}

Node *create_node(int x) {
    //
    Node *p{new Node};

    p->key = x;
    p->next = NULL;

    return p;
}

void create_list(List &l) {
    //
    l.head = NULL;
    l.tail = NULL;
}
