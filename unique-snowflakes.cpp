// cco07p2 (DMOJ)
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

void identify_identical(const vector<size_t> &);
bool identical_right(const vector<size_t> &, const vector<size_t> &, int);
bool identical_left(const vector<size_t> &, const vector<size_t> &, int);
bool identical_left(const vector<size_t> &, const vector<size_t> &);

int main() {

    // vector<size_t> v{1, 2, 3, 1, 5};
    // identify_identical(v);

    return 0;
}

bool identical_left(const vector<size_t> &v1, const vector<size_t> &v2) {

    for (size_t start{0}; start < 6; start++) {
        if (identical_left(v1, v2, start))
            return true;

        if (identical_right(v1, v2, start))
            return true;
    }

    return false;
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
