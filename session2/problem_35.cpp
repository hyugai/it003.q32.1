#include <iostream>
#include <vector>

using namespace std;

void input(int &n, vector<int> &v);

int main() {
    //
    int n;
    vector<int> v;

    input(n, v);

    return 0;
}

void input(int &n, vector<int> &v) {
    //
    cin >> n;
    v.resize(n);

    int i{0};
    while (i < n) {
        cin >> v.at(i);
    }
}
