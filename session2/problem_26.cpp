/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported define include class template
###End banned keyword*/

// #include <iostream>
// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

// ###INSERT CODE HERE -
typedef int ll;

void input(ll &, ll &, ll *&, ll *&);
ll my_binary_search(ll *const &, const ll &, const ll &);
void solve(const ll &, const ll &, ll *const &, ll *const &);

int main() {
    //
    ll n, t, *a{nullptr}, *k{nullptr};
    input(n, t, a, k);

    solve(n, t, a, k);

    //
    delete[] a;
    delete[] k;

    return 0;
}

void solve(const ll &n, const ll &t, ll *const &a, ll *const &k) {
    ll i{0};

    while (i < t) {
        cout << my_binary_search(a, n, k[i]) << '\n'; // \n is faster than endl

        i++;
    }
}

ll my_binary_search(ll *const &a, const ll &n, const ll &x) {
    //
    ll l{0}, r{n - 1}, m;

    //
    ll ans{n};

    while (l <= r) {
        m = l + (r - l) / 2; // avoid buffer overflow
        auto key{a[m]};

        if (key == x) {
            if (m - 1 >= 0) {
                if (a[m - 1] < x)
                    return n - m; //

                if (a[m - 1] == x) {
                    l = r = m - 1;

                    continue;
                }
            } else {
                return n;
            }
        }

        if (key < x) { // m = 0
            l = m + 1;

            ans = l;
        } else {
            r = m - 1;
        }
    }

    return n - ans;
}

void input(ll &n, ll &t, ll *&a, ll *&k) {
    cin >> n;
    cin >> t;

    a = new ll[n];
    k = new ll[t];

    ll temp{0};
    while (temp < n) {
        ll x;
        cin >> x;

        a[temp] = x;

        temp++;
    }

    temp = 0;
    while (temp < t) {
        ll x;
        cin >> x;

        k[temp] = x;

        temp++;
    }
}
