/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported define include
###End banned keyword*/

#include <iostream>
#include <string>
using namespace std;

struct SinhVien {
    int maso;
    string ten;
    int diem;
};

// ###INSERT CODE HERE -

bool greater_student(SinhVien const &lhs, SinhVien const &rhs) {
    if (lhs.diem > rhs.diem) {
        return true;
    } else if (lhs.diem == rhs.diem) {
        /*
         * lexical order:
         *  -> convert to lower case
         *  -> sub-string will be lower (i.e: Hoa vs Hoang)
         *  -> alphabet order
         * */
        if (lhs.ten < rhs.ten) { // bug: increasing not decreasing (fixed)
            return true;
        }
    }

    return false;
}

void insertionSort(SinhVien *a, int const &n, int i = 1) {
    /*
     * base case
     * */
    if (i == n) {
        return;
    }

    /*
     * sorted array -> a[0:i-1]
     * value to insert -> a[i]
     * remaining -> a[i+1:n]
     * */

    int j{i - 1};
    SinhVien value_to_insert{a[i]};

    while (j >= 0 && greater_student(value_to_insert, a[j])) {
        a[j + 1] = a[j];

        // cout << a[j + 1].ten << endl;

        j--;
    }

    a[++j] = value_to_insert;

    return insertionSort(a, n, ++i);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    SinhVien *a = new SinhVien[n];
    for (int i = 0; i < n; i++)
        cin >> a[i].maso >> a[i].ten >> a[i].diem;

    insertionSort(a, n);

    for (int i = 0; i < n; i++) {
        cout << a[i].maso << ' ' << a[i].ten << ' ' << a[i].diem << '\n';
    }
    return 0;
}
