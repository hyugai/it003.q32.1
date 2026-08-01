/*###Begin banned keyword - each of the following line if appear in code will
raise error. regex supported define include class template
###End banned keyword*/

#include <iostream>

using namespace std;

// ###INSERT CODE HERE -
void input(int &n, int *&a);
void print_array(const int &n, int *const &a);
void print_iteration(int const &i, int const &insert_idx);
void my_insertion_sort(int const &n, int *&a, int i = 1);

int main() {
    //
    int n, *a{nullptr};

    input(n, a);

    if (n == 0) {
        cout << "Mang rong.\n";
    } else {
        cout << "Mang truoc khi sap xep la: ";
        print_array(n, a);

        my_insertion_sort(n, a);

        cout << "Mang sau khi sap xep la: ";
        print_array(n, a);
    }

    //
    delete[] a;

    return 0;
}

void my_insertion_sort(int const &n, int *&a, int i) {
    // base case
    if (i == n) {
        return;
    }

    int insert_value{a[i]}, j{i - 1}; // j is moving index

    while (j >= 0 && a[j] < insert_value) {
        a[j + 1] = a[j];

        j--;
    }
    j++; // increase back to value greater less than or equal to insert_value

    print_iteration(i, j);

    a[j] = insert_value;

    print_array(n, a);

    return my_insertion_sort(n, a, ++i);
}

void print_iteration(int const &i, int const &insert_idx) {
    //
    cout << "Vi tri chen cua a[" << i << "] la " << insert_idx << '\n';
}

void print_array(const int &n, int *const &a) {
    //
    int i{0};

    while (i < n)
        cout << a[i++] << ' ';

    cout << '\n';
}

void input(int &n, int *&a) {
    //
    cin >> n;

    a = new int[n];

    int i{0}, x;
    while (i < n) {
        cin >> x;
        a[i] = x;

        ++i;
    }
}
