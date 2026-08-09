#include <iostream>
#include <string>

using namespace std;

void input(int &n, int *&a);
void merge_sort(int left, int right, int *a);
void print_array(int l, int r, int *a);

int main() {
    //
    int n;
    int *a{nullptr};

    input(n, a);

    merge_sort(0, n - 1, a);

    delete[] a;
    return 0;
}

void foo(string &s, int l, int r, int *a) {
    //
    s += '[';

    while (l <= r) {
        s += to_string(a[l]) + (l == r ? "" : ",");

        l++;
    }

    s += ']';
}

void print_array(int l, int r, int *a) {
    while (l <= r) {
        cout << a[l] << ' ';

        l++;
    }

    cout << '\n';
}

void merge_sort(int left, int right, int *a) {
    //
    if (left < right) {
        int m{left + (right - left) / 2};

        string s;
        foo(s, left, m, a);

        s += ',';
        foo(s, m + 1, right, a);
        cout << "k= :\n" << s << endl;

        merge_sort(left, m, a);
        merge_sort(m + 1, right, a);
    } else if (left == right) {
    }
}

void input(int &n, int *&a) {
    //
    cin >> n;

    a = new int[n];

    int i{0};
    while (i < n) {
        cin >> a[i];

        i++;
    }
}
