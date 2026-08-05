/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported define include
###End banned keyword*/

#include <iostream>
using namespace std;

// ###INSERT CODE HERE -
void my_swap(int &l, int &r) {
    int t{l};

    l = r;
    r = t;
}

void qs_partition(int i, int &left, int right, int *a) {
    /*
     * base case -> reach pivot
     * */
    if (i == right) {
        my_swap(a[left], a[right]);

        return;
    }

    if (a[i] <= a[right]) {
        my_swap(a[i], a[left]);

        left++;
    }

    return qs_partition(++i, left, right, a);
}

void quickSort(int *a, int left, int right) {
    /*
     * base case -> 0 or only 1 element to sort
     * */
    if (left >= right) {
        return;
    }

    int i{left}, p{left};

    qs_partition(i, p, right, a);

    quickSort(a, left, p - 1);
    quickSort(a, p + 1, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (n > 0)
        quickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        if (i)
            cout << ' ';
        cout << a[i];
    }
    cout << '\n';
    return 0;
}
