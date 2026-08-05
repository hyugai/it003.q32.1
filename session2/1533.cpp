/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported define include
###End banned keyword*/
#include <iostream>

using namespace std;

void QuickSort(int[], int, int);

int main() {
    int *ls = NULL;
    int n;
    cin >> n;
    ls = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> ls[i];
    }
    QuickSort(ls, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << ls[i] << ' ';
    }
    delete[] ls;
    return 0;
}

void QuickSort(int ls[], int b, int e) {

    // ###INSERT CODE HERE -
    int i{b}, j{e}, pivot{ls[b + (e - b) / 2]};

    while (i <= j) {

        while (ls[i] < pivot) {
            i++;
        }

        while (ls[j] > pivot) {
            j--;
        }

        if (i <= j) {
            int t{ls[i]};
            ls[i] = ls[j];
            ls[j] = t;

            i++;
            j--;
        }
    }

    if (j > b) {
        QuickSort(ls, b, j);
    }
    if (i < e) {
        QuickSort(ls, i, e);
    }
}
