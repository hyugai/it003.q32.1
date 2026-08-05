#include <cstddef>
#include <iostream>

using namespace std;

int main() {
    //
    int *a, *b;
    a = NULL;
    b = NULL;

    if (a == NULL && b != NULL || a != NULL && b == NULL) {
        cout << "long\n";
    }

    if (a ^ b) { // error
    }

    return 0;
}
