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
void input(int &n, int &t, int *&a, int *&k);
void my_binary_search(int &l, int &r, const int &target, const int &n,
                      int *const &a);
void solve(const int &n, const int &t, int *const &a, int *const &k);

int main() {
    //
    int n, t, *a{nullptr}, *k{nullptr};

    input(n, t, a, k);

    solve(n, t, a, k);

    delete[] a;
    delete[] k;

    return 0;
}

void solve(const int &n, const int &t, int *const &a, int *const &k) {
    //
    int i{0};

    while (i < t) {
        int l{0}, r{n - 1}, target{k[i]};

        my_binary_search(l, r, target, n, a);

        if (l > r) {
            printf("-1\n");
        } else {
            printf("%d %d %d\n", r - l - 1, l + 2, r);
        }

        i++;
    }
}

void my_binary_search(int &l, int &r, const int &target, const int &n,
                      int *const &a) {
    //
    if (l > r)
        return;

    int m{l + (r - l) / 2}, mid_value{a[m]};

    if (mid_value == target) {
        l = r = m;

        while (l >= 0 && a[l] == target) {
            l--;
        }

        while (r < n && a[r] == target) {
            r++;
        }

        return;
    }

    if (mid_value < target) {
        l = m + 1;
    } else {
        r = m - 1;
    }
    return my_binary_search(l, r, target, n, a);
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
