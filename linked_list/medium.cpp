struct Node {
    int val;
    Node *next{nullptr};
};

struct ListNode {
    Node *head{nullptr};
    Node *tail{nullptr};
};

bool remove_first_node_x_loop(ListNode l, int x) {
    //
    Node *prev_p{l.head}, *p{l.head};

    while (p) {
        if (p->val == x) {
            // list has only 1 element
            if (prev_p == p) {
                delete p;

                prev_p = p = nullptr;
            } else {
                prev_p->next = p->next;

                delete p;
            }

            return true;
        }

        prev_p = p;
        p = p->next;
    }

    return false;
}

bool remove_first_node_x_recursion(Node *prev_p, Node *p, int x) {
    if (!p) {
        return false;
    }

    if (p->val == x) {
        prev_p->next = p->next;
        delete p;

        return true;
    }

    prev_p = p;
    p = p->next;

    return remove_first_node_x_recursion(prev_p, p, x);
}
