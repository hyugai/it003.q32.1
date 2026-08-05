#include <algorithm>
#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;

static vector<size_t> swap_idxes;

void input(ll &n, vector<ll> &v);
void print_array(const vector<ll> &v);
void my_qs(ll left, ll right, vector<ll> &v);
void qs_partition(ll &left, ll &right, vector<ll> &v);
void print_swap_idxes();

int main() {
    //
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    vector<ll> v;

    input(n, v);
    cout << "Day truoc khi sap xep: ";
    print_array(v);

    my_qs(0, n - 1, v);
    cout << "Day sau khi sap xep: ";
    print_array(v);

    print_swap_idxes();

    return 0;
}

void print_swap_idxes() {
    //
    cout << "Cac hoan vi duoc thuc hien trong Quick Sort:\n";

    size_t i{0};

    while (i < swap_idxes.size()) {
        cout << swap_idxes[i] + 1 << (i % 2 ? '\n' : ' ');

        i++;
    }
}

void my_qs(ll left, ll right, vector<ll> &v) {
    //
    ll i{left}, j{right};
    qs_partition(i, j, v);

    if (j > left) {
        my_qs(left, j, v);
    }

    if (i < right) {
        my_qs(i, right, v);
    }
}

void qs_partition(ll &left, ll &right, vector<ll> &v) {
    //
    ll pivot{v[left + (right - left) / 2]};

    while (left <= right) {
        while (v[left] > pivot) {
            left++;
        }

        while (v[right] < pivot) {
            right--;
        }

        if (left <= right) {
            if (left != right) {
                swap(v[left], v[right]);
                swap_idxes.push_back(left);
                swap_idxes.push_back(right);
            }

            left++;
            right--;
        }
    }
}

void print_array(const vector<ll> &v) {
    for (auto &e : v) {
        cout << e << ' ';
    }

    cout << '\n';
}

void input(ll &n, vector<ll> &v) {
    //
    cin >> n;

    v.resize(n);

    size_t i{0};

    while (i < n) {
        cin >> v[i];

        i++;
    }
}
