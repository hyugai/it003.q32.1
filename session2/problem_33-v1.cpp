#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

void input(int &n, vector<int> &v);
void my_swap(int const &i, int const &j, vector<int> &v);
void print_array(vector<int> const &v);
int qs_partition(int const &target, int &l, int &r, vector<int> &v);
void my_qs(int l, int r, vector<int> &v);

int main() {
    //
    int n;
    vector<int> v;

    input(n, v);
    printf("Day truoc khi sap xep: ");
    print_array(v);

    my_qs(0, n - 1, v);
    printf("Day sau khi sap xep: ");
    print_array(v);

    return 0;
}

void print_array(vector<int> const &v) {
    for (auto e : v) {
        printf("%d ", e);
    }

    printf("\n");
}

void my_qs(int l, int r, vector<int> &v) {
    // base case: 0 or 1 element in bound
    if (l >= r) {
        return;
    }

    int m{l + (r - l) / 2}, i{l}, j{j};

    int p{qs_partition(v.at(m), i, j, v)};
}

int qs_partition(int const &target, int &i, int &j, vector<int> &v) {
    // base case
    if (i >= j) {
        return j;
    }

    while (v.at(i) > target) {
    }
}

void my_swap(int const &i, int const &j, vector<int> &v) {
    //
    int t{v.at(i)};

    v.at(i) = v.at(j);
    v.at(j) = t;
}

void input(int &n, vector<int> &v) {
    //
    cin >> n;

    int i{0}, x;

    while (i < n) {
        cin >> x;
        v.push_back(x);

        i++;
    }
}
