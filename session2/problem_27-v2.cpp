// #include <iostream>
// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

// ###INSERT CODE HERE
void input_array(const int &n, int *&a);
void input(int &n, int &t, int *&a, int *&k);
void my_binary_search(int l, int r, const int &target, int *const &a);
void my_binary_search_left(int l, int r, const int &target, int *const &a);
void my_binary_search_right(int l, int r, const int &target, int *const &a);

int main() {
    //
    int n, t, *a{nullptr}, *k{nullptr};

    input(n, t, a, k);

    //
    delete[] a;
    delete[] k;

    return 0;
}

void my_binary_search(int l, int r, const int &target, int *const &a) {
    //
    if (l > r) {
        return;
    }

    int m{l + (r - l) / 2}, mid_value{a[m]};

    if (mid_value == target) {
        my_binary_search_left(l, m - 1, target, a);
        my_binary_search_left(m + 1, r, target, a);

        return;
    }

    if (mid_value < target) {
        l = m + 1;
    } else {
        r = m - 1;
    }

    return my_binary_search(l, r, target, a);
}

void my_binary_search_left(int l, int r, const int &target, int *const &a) {
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

void my_binary_search_right(int l, int r, const int &target, int *const &a) {
    //
    if (l > r) {
        return;
    }

    int m{l + (r - l) / 2}, mid_value{a[m]};

    if (mid_value < target) {
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
