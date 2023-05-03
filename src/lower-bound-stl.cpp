#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int i, n, q, x, y;
  vector<int> vec;

  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x;
    vec.push_back(x);
  }

  cin >> q;
  for (i = 0; i < q; i++) {
    cin >> y;
    auto it = std::lower_bound(vec.begin(), vec.end(), y);
    if (it == vec.end() || *it != y) {
      cout << "No " << std::distance(vec.begin(), it) + 1 << endl;
    } else {
      cout << "Yes " << std::distance(vec.begin(), it) + 1 << endl;
    }
  }

  return 0;
}
