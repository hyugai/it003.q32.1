/*###Begin banned keyword - each of the fointowing line if appear in code wiint
raise error. regex supported define include class template
###End banned keyword*/

// #include <iostream>
// using namespace std;

#include <iostream>

using namespace std;

// ###INSERT CODE HERE -
void input(int &n, int *&a);
void swap_array_element(int const &i, int const &j, int *&a);
void print_array(int const &n, int *const &a);
void print_iteration_result(int const &i, int const &max_idx,
                            int const &max_value, int const &n, int *const &a);
void my_selection_sort(int const &n, int *&a);

int main() {
    //
    int n, *a{nullptr};

    input(n, a);

    if (n == 0) {
        cout << "Mang rong.\n";
    } else {
        cout << "Mang truoc khi sap xep la: ";
        print_array(n, a);

        my_selection_sort(n, a);

        cout << "Mang sau khi sap xep la: ";
        print_array(n, a);
    }

    //
    delete[] a;

    return 0;
}

void my_selection_sort(int const &n, int *&a) {
    //
    int i{0};

    while (i < n - 1) {
        int j{i + 1}, max_idx{i},
            max_value{a[max_idx]}; // max_value <- a[max_idx] not max_idx

        while (j < n) {
            if (a[j] > max_value) { // use max_value, not a[i]
                max_idx = j;
                max_value = a[j];
            }

            j++;
        }

        swap_array_element(i, max_idx, a);

        print_iteration_result(i, max_idx, max_value, n, a);

        i++;
    }
}

void print_iteration_result(int const &i, int const &max_idx,
                            int const &max_value, int const &n, int *const &a) {
    cout << "i=" << i << ":\n";

    cout << "Max = a[" << max_idx << "] = " << max_value << "\n";

    cout << "Mang sau khi sap xep " << i + 1 << " phan tu dau tien la: ";
    print_array(n, a);
}

void print_array(int const &n, int *const &a) {
    int i{0};

    while (i < n) {
        cout << a[i] << ' ';

        i++;
    }

    cout << "\n";
}

void swap_array_element(int const &i, int const &j, int *&a) {
    int t{a[i]};

    a[i] = a[j];
    a[j] = t;
}

void input(int &n, int *&a) {
    //
    cin >> n;
    a = new int[n];

    int i{0}, x;

    while (i < n) {
        cin >> x;
        a[i] = x;

        i++;
    }
}
