#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

void input(int &n, vector<int> &v);
void my_swap(int const &i, int const &j, vector<int> &v);
void print_array(vector<int> const &v);
void qs_partition(int const &target, int &l, int &r, vector<int> &v);
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
    // base case; no element (l > r), only 1 element (l = r)
    if (l >= r) {
        return;
    }

    int m{l + (r - l) / 2}, i{l}, j{r};

    // printf("abc");
    qs_partition(v.at(m), i, j, v);

    printf("%d %d\n", i, r);
    // printf("def");
    // my_qs(i, r, v);
}

void qs_partition(int const &target, int &i, int &j, vector<int> &v) {
    //
    if (i == j) {
        return;
    }

    while (v.at(i) > target) {
        i++;
    }

    while (v.at(j) < target) {
        j--;
    }

    if (i <= j) {
        my_swap(i, j, v);
    }

    return qs_partition(target, i, j, v);
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
