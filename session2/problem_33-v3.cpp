#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

static vector<ll> swap_idxes;

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

    cout << "Cac hoan vi duoc thuc hien trong Quick Sort:\n";
    print_swap_idxes();

    //
    delete[] a;

    return 0;
}

void print_swap_idxes() {
    ll i{0};

    while (i < swap_idxes.size()) {
        cout << swap_idxes.at(i) + 1 << (i % 2 ? '\n' : ' ');

        i++;
    }
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
                swap_idxes.push_back(left);
                swap_idxes.push_back(right);
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
