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

void qs_partition(int i, int &left, int right, int *a) {}

void quickSort(int *a, int left, int right) {
    int i{left}, j{right}, pivot{a[left + (right - left) / 2]};

    while (i <= j) {
        while (a[i] < pivot) {
            i++;
        }

        while (a[j] > pivot) {
            j--;
        }

        if (i <= j) {
            my_swap(a[i], a[j]);

            i++;
            j--;
        }
    }

    if (j > left) {
        quickSort(a, left, j);
    }

    if (i < right) {
        quickSort(a, i, right);
    }
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
