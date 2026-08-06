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

    int idxes[]{b, b + (e - b) / 2, e, -1};

    for (int *i{idxes}; *i != e; i++) {
        int min_idx{*i};

        for (int *j{++i}; *j != -1; j++) {
        }
    }
}
