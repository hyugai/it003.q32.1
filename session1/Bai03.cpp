#include <cstddef>
#include <vector>
#include <iostream>

using namespace std;

void input_vector(vector<int> &);
int my_binary_search(const vector<int> &, const int &);

int main() {
    vector<int> ma_so;
    input_vector(ma_so);

    int x;
    cin >> x;

    cout << my_binary_search(ma_so, x) << endl;
}

void input_vector(vector<int> &v) {
    int n;
    cin >> n;

    int x;
    for (auto i = 0; i < n; ++i) {
        cin >> x;
        v.push_back(x);
    }
}

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
