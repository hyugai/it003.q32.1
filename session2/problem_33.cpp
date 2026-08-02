#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

void input(int &n, vector<int> &v);
void my_swap(int const &i, int const &j, vector<int> &v);
void qs_partition(int &i, int &left, int right, vector<int> &v);
void my_qs(int left, int right, vector<int> &v);
void print_array(vector<int> const &v);
void print_swap_idxes();

static vector<int> swap_idxes;

int main() {
    //
    int n;
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
    //
    printf("Cac hoan vi duoc thuc hien trong Quick Sort:\n");

    int i{0};
    while (i < swap_idxes.size()) {
        cout << swap_idxes.at(i) + 1 << (i % 2 ? '\n' : ' ');

        i++;
    }
}

void print_array(vector<int> const &v) {
    for (auto e : v) {
        printf("%d ", e);
    }

    printf("\n");
}

void my_qs(int left, int right, vector<int> &v) {
    // base case: left = right -> stop; however, right will be substracted from
    // 1 leading to the condition must be `greater or equal to`
    if (left >= right) {
        return;
    }

    int i{left}, p{left};

    qs_partition(i, p, right, v);

    my_qs(left, p - 1, v);
    my_qs(p + 1, right, v);
}

void qs_partition(int &i, int &left, int right, vector<int> &v) {
    // base case
    if (i == right) {
        my_swap(left, right, v);

        return;
    }

    if (v.at(i) <= v.at(right)) {
        my_swap(i, left, v);

        swap_idxes.push_back(i);
        swap_idxes.push_back(right);

        left++; // move to next position
    }

    i++; // move to next position

    return qs_partition(i, left, right, v);
}

void my_swap(int const &i, int const &j, vector<int> &v) {
    int t{v.at(i)};

    v.at(i) = v.at(j);
    v.at(j) = t;
}

void input(int &n, vector<int> &v) {
    cin >> n;

    int i{0}, x;

    while (i < n) {
        cin >> x;
        v.push_back(x);

        i++;
    }
}
