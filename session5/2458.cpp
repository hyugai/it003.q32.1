/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported
include
class template struct
###End banned
keyword*/

#include <iostream>

using namespace std;

struct node {
    int data;
    node *left;
    node *right;
};

int kiemTraNhanhTrai(node *root, int x);
int kiemTraNhanhPhai(node *root, int x);

void inDanhSachGiamDan(node *TREE);

string chuyenNhiPhan(int x);

bool kiemTraDoiXung(string s);
void demSoChuoiDoiXung(node *TREE, int &cnt);

node *themPhanTuVaoCay(node *&root, int x);

int main() {
    node *TREE = NULL;
    int x, cnt = 0;
    while (scanf("%d", &x)) {
        if (x == 0) {
            inDanhSachGiamDan(TREE);
            cout << endl;
            demSoChuoiDoiXung(TREE, cnt);
            cout << "Co " << cnt << " node thoa de bai." << endl;
            break;
        } else
            themPhanTuVaoCay(TREE, x);
    }
}

// ###INSERT CODE HERE -
node *create_node(int x) {
    node *p{new node};

    p->data = x;

    return p;
}

node *themPhanTuVaoCay(node *&root, int x) {
    if (!root) {
        root = create_node(x);

        return root;
    }

    // if (x == root->data) {
    //     return root;
    // }

    return x < root->data ? themPhanTuVaoCay(root->left, x)
                          : themPhanTuVaoCay(root->right, x);
}

void inDanhSachGiamDan(node *TREE) {
    if (TREE) {
        inDanhSachGiamDan(TREE->right);
        cout << TREE->data << ' ';
        inDanhSachGiamDan(TREE->left);
    }
}

string chuyenNhiPhan(int x) {
    //
    string s{""};

    while (x) {
        s.insert(0, to_string(x % 2));

        x /= 2;
    }

    return s;
}

bool kiemTraDoiXung(string s) {
    //
    size_t i{0}, len{s.length()};

    while (i <= len / 2) {
        if (s.at(i) != s.at(len - i - 1)) {
            return false;
        }

        i++;
    }

    return true;
}

void demSoChuoiDoiXung(node *TREE, int &cnt) {
    if (TREE) {
        demSoChuoiDoiXung(TREE->left, cnt);

        string s{chuyenNhiPhan(TREE->data)};
        cnt += (kiemTraDoiXung(s) ? 1 : 0);

        demSoChuoiDoiXung(TREE->right, cnt);
    }
}
