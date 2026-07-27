#include <vector>
#include <iostream>

using namespace std;

void input_vector(vector<int> &);
int my_linear_search(const vector<int> &, const int &);

int main() {
    // nhap danh sach ma
    vector<int> ma_san_pham;
    input_vector(ma_san_pham);

    // nhap ma can tim
    int x;
    cin >> x;

    // xuat so lan x xuat hien
    cout << my_linear_search(ma_san_pham, x) << endl;
}

//
void input_vector(vector<int> &v) {
    int n;
    cin >> n;

    int x;
    for (auto i = 0; i < n; ++i) {
        cin >> x;
        v.push_back(x);
    }
}

//
int my_linear_search(const vector<int> &v, const int &x) {
    int x_count{0};

    for (auto i = 0; i < v.size(); ++i) {
        if (v.at(i) == x) {
            x_count++;
        }
    }

    return x_count;
}
