#include <cstdio>
#include <iostream>

using namespace std;

struct fraction {
    int top, bot;
};

void input(int &n, fraction *&frac_list);
bool greater_fraction(fraction const &l, fraction const &r);
void my_swap(fraction *const l, fraction *const r);
void print_array(int const &n, fraction *const &frac_list);
void print_iteration_selection_sort(int const &i, int const &n,
                                    fraction *const &frac_list);
void my_selection_sort(int const &n, fraction *const &frac_list, int i = 0);
bool greater_equal_fraction(fraction const &l, fraction const &r);
bool equal_fraction(fraction const &l, fraction const &r);
void my_binary_search(int &l, int &r, fraction const &target,
                      fraction *const &frac_list);

int main() {
    //
    int n;
    fraction *frac_list{nullptr};

    input(n, frac_list);
    my_selection_sort(n, frac_list);

    int l{0}, r{n - 1};
    my_binary_search(l, r, frac_list[n], frac_list);
    if (equal_fraction(frac_list[l], frac_list[n])) {
        printf("Tim thay phan so bang X tai vi tri be nhat la: %d\n", l + 1);
    } else {
        printf("Khong tim thay phan so bang X\n");
    }

    //
    delete[] frac_list;

    return 0;
}

void my_binary_search(int &l, int &r, fraction const &target,
                      fraction *const &frac_list) {
    // base case
    if (l > r) {
        return;
    }

    int m{l + (r - l) / 2};

    printf("[Left=%d, Mid=%d, Right=%d]\n", l + 1, m + 1, r + 1);

    if (greater_equal_fraction(frac_list[m], target)) {
        r = m - 1;
    } else {
        l = m + 1;
    }

    return my_binary_search(l, r, target, frac_list);
}

bool equal_fraction(fraction const &l, fraction const &r) {
    int diff{l.top * r.bot - r.top * l.bot};

    return diff == 0 ? true : false;
}

bool greater_equal_fraction(fraction const &l, fraction const &r) {
    int diff{l.top * r.bot - r.top * l.bot};

    return diff >= 0 ? true : false;
}

void my_selection_sort(int const &n, fraction *const &frac_list, int i) {
    // reach last element
    if (i == n - 1) {
        return;
    }

    int j{i + 1}, min_idx{i};

    while (j < n) {
        if (greater_fraction(frac_list[min_idx], frac_list[j])) {
            min_idx = j;
        }

        j++;
    }

    my_swap(&frac_list[i], &frac_list[min_idx]);

    print_iteration_selection_sort(i, n, frac_list);

    i++; // next element

    my_selection_sort(n, frac_list, i);
}

void print_iteration_selection_sort(int const &i, int const &n,
                                    fraction *const &frac_list) {
    //
    printf("#STEP %d:\n", i + 1);
    print_array(n, frac_list);
}

void print_array(int const &n, fraction *const &frac_list) {
    //
    int i{0};

    while (i < n) {
        printf("%d/%d ", frac_list[i].top, frac_list[i].bot);

        i++;
    }

    printf("\n");
}

void my_swap(fraction *const l, fraction *const r) {
    fraction t{*l};

    *l = *r;
    *r = t;
}

bool greater_fraction(fraction const &l, fraction const &r) {
    //
    int diff{l.top * r.bot - r.top * l.bot};

    return diff > 0 ? true : false;
}

void input(int &n, fraction *&frac_list) {
    //
    cin >> n;

    frac_list = new fraction[n + 1];

    int i{0}, top, bot;

    while (i <= n) {
        cin >> top >> bot;

        frac_list[i].top = top;
        frac_list[i].bot = bot;

        i++;
    }
}
