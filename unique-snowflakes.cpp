// cco07p2 (DMOJ)
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

void input(size_t &, vector<size_t> &);
size_t get_matrix_idx(const size_t &);
void identify_identical(const vector<size_t> &);
bool identical_right(const vector<size_t> &, const vector<size_t> &, int);
bool identical_left(const vector<size_t> &, const vector<size_t> &, int);

int main() {

    size_t n;
    vector<size_t> snowflakes;

    return 0;
}

bool identical_left(const vector<size_t> &v1, const vector<size_t> &v2,
                    int v2_start_idx) {

    for (size_t offset{0}; offset < 6; offset++) {
        size_t v2_idx{v2_start_idx - offset};

        v2_idx += v2_idx < 0 ? 6 : 0;

        if (v1.at(offset) != v2.at(v2_idx))
            return false;
    }

    return true;
}

bool identical_right(const vector<size_t> &v1, const vector<size_t> &v2,
                     int v2_start_idx) {

    for (size_t offset{0}; offset < 6; offset++) {
        if (v1.at(offset) != v2.at((v2_start_idx + offset) % 6))
            return false;
    }

    return true;
}

void identify_identical(const vector<size_t> &v) {

    for (size_t i{0}; i < v.size(); i++) {
        for (size_t j{i + 1}; j < v.size(); j++) {
            if (v.at(i) == v.at(j)) {
                cout << "Twin integers found." << endl;
                return;
            }
        }
    }

    cout << "No two integers are alike." << endl;
}

size_t get_matrix_idx(const size_t &) {
    size_t idx;
    return idx;
}

void input(size_t &n, vector<size_t> &v) {

    cin >> n;

    for (size_t i{0}; i < n; i++) {
        size_t x;
        cin >> x;
        v.push_back(x);
    }
}
