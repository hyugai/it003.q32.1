#include <iostream>
#include <vector>

using namespace std;

int main() {
  {
    vector<int> v; // empty
  }

  {
    vector<int> v(4); // {0, 0, 0, 0}
  }

  {
    vector<int> v(4, 7); // {7, 7, 7, 7}
  }

  {
    vector<int> v{2, 4, 6}; // {2, 4, 6}
  }

  {
    vector<int> v{3, 5}; // {3, 5}

    v.push_back(8); // {3, 5, 8}

    v.pop_back(); // {3, 5}

    cout << v.size(); // 2

    cout << (v.empty() ? "Empty" : "Non-empty"); // false

    cout << v.front(); // first element -> 3
    cout << v.back();  // last element -> 5

    for (auto it = v.begin(); it != v.end(); ++it) {
      /*
           Vector Elements:   [ 10 ]  [ 20 ]  [ 30 ]  [ 40 ]
                                ▲                              ▲
                                │                              │
                            v.begin()                      v.end()
                        (Points to first)             (Points past last)

       * [begin(),end())
       */
    }
  }

  return 0;
}
