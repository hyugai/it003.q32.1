/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported define include lower_bound upper_bound
binary_search
equal_range
###End banned keyword*/

#include <iostream>
using namespace std;

int a[100005];

// ###INSERT CODE HERE -
int countLessEqual(int *const &a, int const &n, int const &x) {
    /*
     * a1...aN (increasing)
     * aM -> mid value
     * x -> target
     * ...xxx... -> include all duplicates of x -> go right
     *
     * => update lower bound when less than or equal to x
     * */
    int l{0}, r{n - 1};

    while (l <= r) {
        int m{l + (r - l) / 2}, mid_value{a[m]};

        if (mid_value <= x) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    return l;
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
        cout << countLessEqual(a, n, x) << "\n";
    }

    return 0;
}
