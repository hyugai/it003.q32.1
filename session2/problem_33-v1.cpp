#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

static vector<int> swap_idxes;

void input(long long &n, vector<int> &v);
void my_swap(long long const &i, long long const &j, vector<int> &v);
void print_array(vector<int> const &v);
long long qs_partition(long long const &target, long long l, long long r,
                       vector<int> &v);
void my_qs(long long l, long long r, vector<int> &v);
void print_swap_idxes();

int main() {
    //
    long long n;
    vector<int> v;

    input(n, v);
    printf("Day truoc khi sap xep: ");
    print_array(v);

    my_qs(0, n - 1, v);
    printf("Day sau khi sap xep: ");
    print_array(v);

    print_swap_idxes();

    return 0;
}

void print_swap_idxes() {
    printf("Cac hoan vi duoc thuc hien trong Quick Sort:\n");

    long long i{0};

    while (i < swap_idxes.size()) {
        printf("%d%c", swap_idxes.at(i) + 1, (i % 2 ? '\n' : ' '));

        i++;
    }
}

void print_array(vector<int> const &v) {
    for (auto e : v) {
        printf("%d ", e);
    }

    printf("\n");
}

void my_qs(long long l, long long r, vector<int> &v) {
    // base case: 0 or 1 element in bound
    if (l >= r) {
        return;
    }

    // printf("QS l=%d r=%d\n", l, r);
    long long m{l + (r - l) / 2}, target{v.at(m)},
        p{qs_partition(target, l, r, v)};

    my_qs(l, p, v);
    my_qs(p + 1, r,
          v); // my_qs(1,2,v) -> j = 0 -> p = 0 -> my_qs(1,2,v) -> infinite loop
}

long long qs_partition(long long const &target, long long i, long long j,
                       vector<int> &v) {
    // base case
    if (i >= j) {
        return j;
    }

    while (v.at(i) > target) {
        i++;
    }

    while (v.at(j) < target) { // remove equal here ?
        j--;
    }

    if (i < j) {
        my_swap(i, j, v);
        // printf("i=%d j=%d\n", i, j);
        // add increment, decrement here ?

        swap_idxes.push_back(i);
        swap_idxes.push_back(j);

        // test
        i++;
        j--;
    }

    return qs_partition(target, i, j, v);
}

void my_swap(long long const &i, long long const &j, vector<int> &v) {
    //
    long long t{v.at(i)};

    v.at(i) = v.at(j);
    v.at(j) = t;
}

void input(long long &n, vector<int> &v) {
    //
    cin >> n;

    long long i{0}, x;

    while (i < n) {
        cin >> x;
        v.push_back(x);

        i++;
    }
}
