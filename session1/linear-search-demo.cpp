#include <cstddef>
#include <vector>
#include <iostream>

using namespace std;

void input_vector(vector<size_t> &);
size_t my_linear_search(const vector<size_t> &, const size_t &);
size_t my_binary_search(const vector<size_t> &, const size_t &);

int main() {
    vector<size_t> ma_so;
    input_vector(ma_so);

    size_t x;
    cin >> x;

    cout << my_linear_search(ma_so, x) << endl;
}

void input_vector(vector<size_t> &v) {
    size_t x;
    while (cin >> x && x != -1) {
        v.push_back(x);
    }
}

size_t my_linear_search(const vector<size_t> &v, const size_t &x) {
    for (auto i = 0; i < v.size(); ++i) {
        if (v.at(i) == x) {
            return i;
        }
    }

    return -1;
}

size_t my_binary_search(const vector<size_t> &v, const size_t &x) {
    size_t l{0}, r{v.size() - 1}, m{(l + r) / 2};

    while (l <= r) {
        if (x == v.at(m)) {
            return m;
        }

        if (x < m) {
            r = m - 1;
        }

        if (x > m) {
            l = m + 1;
        }
    }

    return -1;
}
