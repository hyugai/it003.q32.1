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
     * this version uses median-of-3
     *
     * if this doesn't work, the randomized version of Quick Sort will be
     * considered
     * */

    /*
     * choose pivot
     *  -> take first, last, and middle element by index
     *  -> sort 3 elements above
     *  -> pivot = middle element
     *
     *  b < mid < e
     *  max = b -> compare mid, e -> found max
     *  min = b -> compare mid, e -> found max
     * */

    int mid{b + (e - b) / 2}, idxes[]{b, mid, e, -1};

    for (int *i{idxes}; *i != e; i++) {
        int min_idx{*i};

        for (int *j{i + 1}; *j != -1; j++) {
            min_idx = (ls[*j] < ls[min_idx] ? *j : min_idx);
        }

        if (min_idx != *i) {
            int t{ls[*i]};

            ls[*i] = ls[min_idx];
            ls[min_idx] = t;
        }
    }

    /*
     * */
    int pivot{ls[mid]}, i{b}, j{e};

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
