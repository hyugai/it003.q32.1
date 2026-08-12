/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported
define include []
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
    //
    if (lhs.Ten != rhs.Ten) {
        return (lhs.Ten < rhs.Ten ? true : false);
    }

    if (lhs.Hodem != rhs.Hodem) {
        int i{0}, j{0};

        while (i < lhs.Hodem.length() && j < rhs.Hodem.length()) {
            if (lhs.Hodem.at(i) == ' ') {
                i++;

                continue;
            }

            if (rhs.Hodem.at(j) == ' ') {
                j++;

                continue;
            }

            i++;
            j++;
        }
    }

    //
    if (lhs.Nam != rhs.Nam) {
        return (lhs.Nam > rhs.Nam ? true : false);
    }

    if (lhs.Thang != rhs.Thang) {
        return (lhs.Thang > rhs.Thang ? true : false);
    }

    if (lhs.Ngay != rhs.Ngay) {
        return (lhs.Ngay > rhs.Ngay ? true : false);
    }

    return false;
}

void swap_data_node(Node *i, Node *j) {
    //
    Hocsinh t{i->data};

    i->data = j->data;
    j->data = t;
}

void Sort(List &l) {
    //
    Node *i{l.head};

    while (i && i->next) {
        Node *min{i};

        Node *j{i->next};

        while (j) {
            if (less_student(j->data, i->data)) {
                min = j;
            }

            j = j->next;
        }

        swap_data_node(i, min);

        i = i->next;
    }
}
