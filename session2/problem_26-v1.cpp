// #include <iostream>
// #include <math.h>
// #include <stdio.h>
// #include <stdlib.h>

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// ###INSERT CODE HERE
void input(int &, int &, int *&, int *&);
void my_binary_search(int &, int &, int &, int &, int *const &);
void solve(const int &, const int &, int *const &, int *const &);

int main() {
    //
    int n, t, *a{nullptr}, *k{nullptr};

    //
    input(n, t, a, k);
    solve(n, t, a, k);

    //
    delete[] a;
    delete[] k;

    return 0;
}

void solve(const int &n, const int &t, int *const &a, int *const &k) {
    //
    int i{0};
    while (i < t) {
        int ans{n}, l{0}, r{n - 1};

        my_binary_search(l, r, k[i], ans, a);

        printf("%d\n", n - ans);
        i++;
    }
}

void my_binary_search(int &l, int &r, int &target, int &ans, int *const &a) {
    // base case
    if (l > r)
        return;

    //
    int m{l + (r - l) / 2}, mid_value{a[m]};
    if (mid_value >= target) {
        r = m - 1;

        if (m < ans) {
            ans = m;
        }
    } else {
        l = m + 1;
    }

    return my_binary_search(l, r, target, ans, a);
}

void input(int &n, int &t, int *&a, int *&k) {
    cin >> n >> t;

    a = new int[n];
    k = new int[t];

    int i{0}, x;

    while (i < n) {
        cin >> x;
        a[i] = x;

        i++;
    }

    i = 0;
    while (i < t) {
        cin >> x;
        k[i] = x;

        i++;
    }
}
