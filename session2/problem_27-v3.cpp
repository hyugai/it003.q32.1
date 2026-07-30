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
void solve(int const &n, int const &t, int *const &a, int *const &k);
int my_binary_search(const bool &is_forward, int l, int r, const int &target,
                     int *const &a);

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
        int l{0}, r{n - 1}, target{k[i]};

        int upper_bound{my_binary_search(true, l, r, target, a)};

        if (a[upper_bound] == target) {
            int lower_bound{my_binary_search(false, l, upper_bound, target, a)};

            printf("%d %d %d\n", upper_bound - lower_bound + 1, lower_bound + 1,
                   upper_bound + 1);
        } else {
            printf("-1\n");
        }

        i++;
    }
}

int my_binary_search(const bool &is_forward, int l, int r, const int &target,
                     int *const &a) {
    //
    if (l > r) {
        return (is_forward ? r : l);
    }

    int m{l + (r - l) / 2}, mid_value{a[m]};

    if (mid_value == target) {
        if (is_forward) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    if (mid_value < target) {
        l = m + 1;
    } else if (mid_value > target) {
        r = m - 1;
    }

    return my_binary_search(is_forward, l, r, target, a);
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
