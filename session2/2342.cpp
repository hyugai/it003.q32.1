/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported define include lower_bound upper_bound
binary_search
equal_range
###End banned keyword*/

#include <iostream>
using namespace std;

int a[100005];

// ###INSERT CODE HERE -
bool binarySearch(int *const &a, int const &n, int const &x) {
    //
    int l{0}, r{n - 1};

    while (l <= r) {
        int m{l + (r - l) / 2}, mid_value{a[m]};

        if (mid_value == x) {
            return true;
        }

        if (mid_value < x) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        cout << (binarySearch(a, n, x) ? "YES" : "NO") << "\n";
    }

    return 0;
}
