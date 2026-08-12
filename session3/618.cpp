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

void Output(List ds) {
    Node *p = ds.head;
    if (p == NULL) {
        cout << "EMPTY";
    }
    while (p != NULL) {
        OutputElement(p->data);
        p = p->next;
    }
}

// ###INSERT CODE HERE -
Node *create_new_node(Hocsinh stu) {
    //
    Node *p{new Node};

    p->next = NULL;
    p->data = stu;

    return p;
}

bool avg_greater_than_9(Hocsinh stu) {
    //
    double sum{stu.Anh + stu.Hoa + stu.Ly + stu.Sinh + stu.Toan + stu.Van};

    return (sum - 54.0 >= 0.0 ? true : false);
}

void input(int &n, List &l) {
    //
    cin >> n;

    int i{0};
    Node *p{NULL};

    l.head = l.tail = p = NULL;

    while (i < n) {
        Hocsinh stu;

        InputElement(stu);

        if (avg_greater_than_9(stu)) {
            Node *t{create_new_node(stu)};

            if (!l.head) {
                l.head = l.tail = p = t;
            } else {
                p->next = t;

                l.tail = p = t;
            }
        }

        i++;
    }
}

int main() {
    //
    int n;
    List l;

    input(n, l);
    Output(l);

    return 0;
}
