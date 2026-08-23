/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported define include
[
]
###End banned keyword*/
#include <iostream>

using namespace std;

struct Hocsinh {
    string Hodem, Ten;
    bool Gioitinh;
    int Ngay, Thang, Nam;
    double Toan, Van, Ly, Hoa, Anh, Sinh;
};

void InputElement(Hocsinh &x) {
    getline(cin >> ws, x.Hodem);
    getline(cin >> ws, x.Ten);
    cin >> x.Gioitinh;
    cin >> x.Ngay >> x.Thang >> x.Nam;
    cin >> x.Toan >> x.Van >> x.Ly >> x.Hoa >> x.Anh >> x.Sinh;
}

void OutputElement(Hocsinh hs) {
    cout << hs.Hodem << ' ' << hs.Ten << '\t' << hs.Gioitinh << '\t' << hs.Ngay
         << '/' << hs.Thang << '/' << hs.Nam << '\t' << hs.Toan << '\t'
         << hs.Van << '\t' << hs.Ly << '\t' << hs.Hoa << '\t' << hs.Anh << '\t'
         << hs.Sinh << endl;
    ;
}

struct Node {
    Hocsinh data;
    Node *next;
};

struct List {
    Node *head, *tail;
};

Node *CreateNode(Hocsinh x) {
    Node *p = new Node;
    if (p == NULL)
        exit(1);
    p->data = x;
    p->next = NULL;
    return p;
}

void CreateList(List &l) { l.head = l.tail = NULL; }

void AddHead(List &l, Hocsinh x) {
    Node *p = CreateNode(x);
    if (l.head == NULL)
        l.tail = p;
    else
        p->next = l.head;
    l.head = p;
}

void AddTail(List &l, Hocsinh x) {
    Node *p = CreateNode(x);
    if (l.head == NULL)
        l.head = p;
    else
        l.tail->next = p;
    l.tail = p;
}

Node *RemoveHead(List &l) {
    if (l.head == NULL)
        return NULL;
    Node *p = l.head;
    l.head = p->next;
    p->next = NULL;
    return p;
}

void PrintList(List l) {
    Node *p = l.head;
    while (p != NULL) {
        OutputElement(p->data);
        p = p->next;
    }
}

void Sort(List &);

int main() {
    List l;
    int n;
    Hocsinh hs;

    CreateList(l);
    cin >> n;
    for (int i = 0; i < n; i++) {
        InputElement(hs);
        AddTail(l, hs);
    }

    Sort(l);
    PrintList(l);
    return 0;
}

// ###INSERT CODE HERE -
bool less_student(Hocsinh lhs, Hocsinh rhs) {
    if (lhs.Ten != rhs.Ten) {
        return lhs.Ten < rhs.Ten ? true : false;
    }

    if (lhs.Hodem != rhs.Hodem) {
        return lhs.Hodem < rhs.Hodem;
    }

    if (lhs.Nam != rhs.Nam) {
        return lhs.Nam > rhs.Nam;
    }

    if (lhs.Thang != rhs.Thang) {
        return lhs.Thang > rhs.Thang;
    }

    if (lhs.Ngay != rhs.Ngay) {
        return lhs.Ngay > rhs.Ngay;
    }

    return false;
}

void swap_student(Node *lhs, Node *rhs) {
    Hocsinh t{lhs->data};

    lhs->data = rhs->data;

    rhs->data = t;
}

void Sort(List &l) {
    if (!l.head || l.head == l.tail) {
        return;
    }

    List left, right;
    CreateList(left), CreateList(right);

    Node *p{l.head->next}, *pivot{l.head};

    while (p) {
        Node *next{p->next};
        p->next = NULL;

        less_student(p->data, pivot->data) ? AddTail(left, p->data)
                                           : AddTail(right, p->data);

        p = next;
    }

    Sort(left);
    Sort(right);

    CreateList(l);

    // merge
    p = left.head;
    while (p) {
        AddTail(l, p->data);

        p = p->next;
    }

    AddTail(l, pivot->data);

    p = right.head;
    while (p) {
        AddTail(l, p->data);

        p = p->next;
    }
}
