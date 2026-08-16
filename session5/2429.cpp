#include <iostream>
#include <list>
#include <map>
#include <vector>

using namespace std;

static list<int> l{};
static map<int, int> count{};
static vector<int> order;

void input() {
    int x;

    cin >> x;

    while (x) {
        l.push_back(x);

        if (!count[x]) {
            order.push_back(x);
        }

        count[x]++;

        cin >> x;
    }
}

void output() {
    if (l.size()) {
        cout << "Danh sach vua nhap la: ";

        for (auto e : l) {
            cout << e << ' ';
        }

        cout << "\nSo lan xuat hien cua tung phan tu trong danh sach la:\n";
        for (auto e : order) {
            cout << e << ": " << count.at(e) << '\n';
        }
    } else {
        cout << "Danh sach rong.\n";
    }
}

int main() {

    input();
    output();

    return 0;
}
