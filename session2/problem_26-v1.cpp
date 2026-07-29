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
int my_binary_search(const int &, const int &, int *const &, int *const &);

int main() {
    //
    int n, t, *a{nullptr}, *k{nullptr};

    //
    input(n, t, a, k);

    //
    delete[] a;
    delete[] k;

    return 0;
}

int my_binary_search(const int &, const int &, int *const &, int *const &) {
    int ans;

    return ans;
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
