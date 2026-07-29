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
void input(int &, int &, int *&, int *&);
void my_binary_search(int l, int r, int &start, int &end, const int &target,
                      int *const &a);
void solve(const int &, const int &, int *const &, int *const &);

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

void solve(const int &n, const int &t, int *const &a, int *const &k) {
    //
    int i{0}, target_count{0};

    while (i < t) {
        int l{0}, r{n - 1}, start{l + (r - l) / 2}, end{start};

        my_binary_search(l, r, start, end, k[i], a);

        if (start == end && a[start] != k[i]) {
            printf("-1\n");
        } else {
            // continuous elements so we only need simple calculation instead of
            // separatete variable
            printf("%d %d %d\n", end - start + 1, start + 1, end + 1);
        }

        i++;
    }
}

void my_binary_search(int l, int r, int &start, int &end, const int &target,
                      int *const &a) {
    // base case
    if (l > r)
        return;

    // start, end init to m in solve function
    int m{l + (r - l) / 2}, mid_value{a[m]};

    if (mid_value <= target) {
        //  start, end init to value different from target
        if (mid_value == target) {
            if (a[start] != target) {
                start = end = m;
            }

            if (m < start) {
                start = m;

                my_binary_search(l, m, start, end, target, a);
            }

            if (m > end) {
                end = m;

                my_binary_search(m, r, start, end, target, a);
            }
        }
        //
        l = m + 1;
    } else {
        r = m - 1;
    }

    return my_binary_search(l, r, start, end, target, a);
}

void input(int &n, int &t, int *&a, int *&k) {
    //
    cin >> n >> t;

    a = new int[n];
    k = new int[t];

    //
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
