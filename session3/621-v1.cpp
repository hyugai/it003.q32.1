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
bool less_student(Hocsinh lhs, Hocsinh rhs) {}

void swap_student(Node *lhs, Node *rhs) {
    //
    Hocsinh t{lhs->data};

    lhs->data = rhs->data;

    rhs->data = t;
}

Node *partition(List l) {
    //
    Hocsinh x{l.tail->data};

    Node *p{l.head}, *q{l.head};

    while (p != l.tail) {
        less_student(p->data, x) ? swap_student(p, q), q = q->next : p;

        p = p->next;
    }

    swap_student(q, l.tail);

    return q;
}

void Sort(List &l) {
    // base case
    if (!l.head || l.head == l.tail) {
        return;
    }

    Node *p{partition(l)};

    List left{}, right{};

    CreateList(left), left.head = l.head, left.tail = p;
    CreateList(right), right.head = p, right.tail = l.tail;

    Sort(left);
    Sort(right);
}
