#include <cstddef>
#include <vector>
#include <iostream>

using namespace std;

void input_vector(vector<int> &);
int my_binary_search(const vector<int> &, const int &);
int find_idx_to_insert(const vector<int> &, const int &, const int &);

int main() {
    // nhap ma so
    vector<int> ma_so;
    input_vector(ma_so);

    // nhap gia tri can chen
    int x;
    cin >> x;

    // tim idx gia tri can chen co trong mang khong
    int idx{my_binary_search(ma_so, x)};

    // tim idx de chen gia tri x
    cout << find_idx_to_insert(ma_so, idx, x) << endl;

    return 0;
}

//
int find_idx_to_insert(const vector<int> &v, const int &idx, const int &x) {
    if (idx == -1) {
        for (auto i{0}; i < v.size(); ++i) {
            if (v.at(i) > x) {
                return i;
            }
        }

        return v.size(); // gia tri x la gia tri lon nhat
    } else {
        for (auto i{0}; i < v.size(); ++i) {
            if (v.at(i) == x)
                return i;
        }
    }

    return 0; // surpass warning
}

//
int my_binary_search(const vector<int> &v, const int &x) {
    size_t l{0}, r{v.size() - 1}, m;

    while (l <= r) {
        m = (l + r) / 2;
        if (x == v.at(m)) {
            return m;
        }

        if (x < v.at(m)) {
            r = m - 1;
        }

        if (x > v.at(m)) {
            l = m + 1;
        }
    }

    return -1;
}

void input_vector(vector<int> &v) {
    int n;
    cin >> n;

    for (auto i{0}; i < n; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
    }
}
