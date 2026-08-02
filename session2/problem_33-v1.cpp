#include <cstddef>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

void input(size_t &n, vector<size_t> &v);
void my_swap(size_t const &i, size_t const &j, vector<size_t> &v);
void qs_partition(size_t const &p, size_t left, size_t right,
                  vector<size_t> &v);
void print_array(vector<size_t> const &v);

int main() {
    //
    size_t n;
    vector<size_t> v;

    input(n, v);
    printf("Day truoc khi sap xep: ");
    print_array(v);

    return 0;
}

void print_array(vector<size_t> const &v) {
    for (auto e : v) {
        printf("%zu ", e);
    }

    printf("\n");
}

void my_qs(size_t left, size_t right, vector<size_t> &v) {
    // base case
    if (left >= right) {
        return;
    }

    size_t p{left + (right - left) / 2}; // p stands for `partition`
    qs_partition(p, left, right, v);

    my_qs(left, p - 1, v);
    my_qs(p + 1, right, v);
}

void qs_partition(size_t const &p, size_t left, size_t right,
                  vector<size_t> &v) {
    // base case
    if (left == right) {
        return;
    }

    while (v.at(left) > v.at(p) && left < p) {
        left++;
    }

    while (v.at(right) < v.at(p) && right > p) {
        right--;
    }

    if (v.at(left) < v.at(right)) {
        my_swap(left, right, v);
    }

    return qs_partition(p, left, right, v);
}

void my_swap(size_t const &i, size_t const &j, vector<size_t> &v) {
    //
    size_t t{v.at(i)};

    v.at(i) = v.at(j);
    v.at(j) = t;
}

void input(size_t &n, vector<size_t> &v) {
    //
    cin >> n;

    size_t i{0}, x;

    while (i < n) {
        cin >> x;
        v.push_back(x);

        i++;
    }
}
