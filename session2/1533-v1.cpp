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
    /*
     * this version uses last element as pivot -> cause TLE
     * */
    if (b >= e) {
        return;
    }

    int pivot{ls[e]}, p{b}, j{b};

    while (j < e) {
        if (ls[j] <= pivot) {
            int t{ls[p]};

            ls[p] = ls[j];
            ls[j] = t;

            p++;
        }

        j++;
    }

    int t{ls[p]};

    ls[p] = pivot;
    ls[e] = t;

    //
    QuickSort(ls, b, p - 1);
    QuickSort(ls, p + 1, e);
}
