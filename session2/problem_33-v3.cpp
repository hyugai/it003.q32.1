#include <iostream>
#include <string>

using namespace std;

using ll = long long;

/*
 * the action of pushing elements to vector does not cause TLE; however, using
 * loop to print its elements does.
 *
 * -> pushing elements to a string, which is printed just once is much faster
 * */
static string output;

void input(ll &n, ll *&a);
void print_array(ll &n, ll *&a);
void my_swap(ll &i, ll &j);
void my_qs_partition(ll &left, ll &right, ll *&a);
void my_qs(ll left, ll right, ll *&a);
void print_swap_idxes();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //
    ll n;
    ll *a{nullptr};

    input(n, a);
    cout << "Day truoc khi sap xep: ";
    print_array(n, a);

    my_qs(0, n - 1, a);
    cout << "Day sau khi sap xep: ";
    print_array(n, a);

    cout << "Cac hoan vi duoc thuc hien trong Quick Sort:\n" << output;

    //
    delete[] a;

    return 0;
}

void my_qs(ll left, ll right, ll *&a) {
    //
    ll i{left}, j{right};

    my_qs_partition(i, j, a);

    if (j > left) {
        my_qs(left, j, a);
    }

    if (i < right) {
        my_qs(i, right, a);
    }
}

void my_qs_partition(ll &left, ll &right, ll *&a) {
    //
    ll pivot{a[left + (right - left) / 2]};

    while (left <= right) {

        while (a[left] > pivot) {
            left++;
        }

        while (a[right] < pivot) {
            right--;
        }

        if (left <= right) {
            my_swap(a[left], a[right]);

            if (left != right) {
                output +=
                    to_string(left + 1) + ' ' + to_string(right + 1) + '\n';
            }

            left++;
            right--;
        }
    }
}

void my_swap(ll &i, ll &j) {
    //
    ll t{i};

    i = j;
    j = t;
}

void print_array(ll &n, ll *&a) {
    //
    ll i{0};

    while (i < n) {
        cout << a[i] << ' ';

        i++;
    }

    cout << '\n';
}

void input(ll &n, ll *&a) {
    //
    cin >> n;
    a = new ll[n];

    ll i{0};
    ll x;

    while (i < n) {
        cin >> x;
        a[i] = x;

        i++;
    }
}
