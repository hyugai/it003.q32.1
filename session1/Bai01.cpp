#include <vector>
#include <iostream>

using namespace std;

void input_vector(vector<int> &);
int my_linear_search(const vector<int> &, const int &);

int main() {
    // nhap danh sach ma
    vector<int> ma_so;
    input_vector(ma_so);

    // nhap ma can tim
    int x;
    cin >> x;

    // xuat so lan x xuat hien
    cout << my_linear_search(ma_so, x) << endl;
}

//
void input_vector(vector<int> &v) {
    int x;
    while (cin >> x && x != -1) {
        v.push_back(x);
    }
}

//
int my_linear_search(const vector<int> &v, const int &x) {
    for (auto i = 0; i < v.size(); ++i) {
        if (v.at(i) == x) {
            return i;
        }
    }

    return -1;
}
