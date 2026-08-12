#include <iostream>

using namespace std;

int main() {
    //
    string s{"Le Gia"};
    int pos = s.find(" ");

    cout << s.substr(0, pos) << endl;
    cout << s.substr(pos + 1, s.length() - pos) << endl;

    return 0;
}
