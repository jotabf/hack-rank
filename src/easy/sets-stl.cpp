#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int q, x, y;
  set<int> st;

  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> x >> y;
    switch (x) {
      case 1:
        st.insert(y);
        break;
      case 2:
        st.erase(y);
        break;
      case 3:
        auto it = st.find(y);
        cout << (it == st.end() ? "No" : "Yes") << endl;
        break;
    }
  }

  return 0;
}