// #include <iostream>
// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// ###INSERT CODE HERE
void input_array(const int &n, int *&a);
void input(int &n, int &t, int *&a, int *&k);
void my_binary_search(int l, int r, const int &target, int *const &a);
void my_binary_search_left(int &l, int r, const int &target, int *const &a);
void my_binary_search_right(int l, int &r, const int &target, int *const &a);
void solve(int const &n, int const &t, int *const &a, int *const &k);

int main() {
    //
    int n, t, *a{nullptr}, *k{nullptr};

    input(n, t, a, k);
    solve(n, t, a, k);

    //
    delete[] a;
    delete[] k;

    return 0;
}

void solve(int const &n, int const &t, int *const &a, int *const &k) {
    int i{0};

    while (i < t) {
        int l{0}, r{n - 1};
        my_binary_search(l, r, k[i], a);

        i++;
    }
}

void my_binary_search(int l, int r, const int &target, int *const &a) {
    //
    if (l > r) {
        printf("-1\n");

        return;
    }

    int m{l + (r - l) / 2}, mid_value{a[m]};

    if (mid_value == target) {
        my_binary_search_left(l, m - 1, target, a);
        my_binary_search_right(m + 1, r, target, a);

        printf("%d %d %d\n", r - l + 1, l + 1, r + 1);

        return;
    }

    if (mid_value < target) {
        l = m + 1;
    } else {
        r = m - 1;
    }

    return my_binary_search(l, r, target, a);
}

void my_binary_search_left(int &l, int r, const int &target, int *const &a) {
    //
    if (l > r) {
        return;
    }

    int m{l + (r - l) / 2}, mid_value{a[m]};

    if (mid_value <= target) {
        l = m + 1;
    } else {
        r = m - 1;
    }

    return my_binary_search_left(l, r, target, a);
}

void my_binary_search_right(int l, int &r, const int &target, int *const &a) {
    //
    if (l > r) {
        return;
    }

    int m{l + (r - l) / 2}, mid_value{a[m]};

    if (mid_value <= target) {
        l = m + 1;
    } else {
        r = m - 1;
    }

    return my_binary_search_right(l, r, target, a);
}

void input(int &n, int &t, int *&a, int *&k) {
    //
    cin >> n >> t;

    a = new int[n];
    k = new int[t];

    input_array(n, a);
    input_array(t, k);
}

void input_array(const int &n, int *&a) {
    //
    int i{0}, x;

    while (i < n) {
        cin >> x;
        a[i] = x;

        i++;
    }
}
