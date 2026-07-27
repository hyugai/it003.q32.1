#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

void input_vector(vector<int> &);
int my_binary_search(const vector<int> &, const int &);

int main() {
    // nhap ma so
    vector<int> ma_so;
    input_vector(ma_so);

    // nhap gia tri can chen
    int x;
    cin >> x;

    // tim idx gia tri can chen co trong mang khong
    cout << my_binary_search(ma_so, x);

    return 0;
}

//
int my_binary_search(const vector<int> &v, const int &x) {
    size_t l{0}, r{v.size() - 1}, m, ans;

    if (x < v.front())
        return 0;
    else if (x > v.back())
        return v.size();

    // idea: let l, r running until they cross
    while (l <= r) {
        m = (l + r) / 2;

        if (x == v.at(m))
            ans = m; // update when found

        if (x >= v.at(m))
            r = m - 1;
        else
            l = m + 1;
    }

    return ans;
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
