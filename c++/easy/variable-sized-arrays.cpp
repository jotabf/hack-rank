#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, q, k, i;
  int ii, jj;

  cin >> n >> q;

  vector<vector<int> > vec(n);

  for (i = 0; i < n; i++) {
    cin >> k;
    vec[i].resize(k);
    for (int j = 0; j < k; j++) {
      cin >> vec[i][j];
    }
  }
  for (i = 0; i < q; i++) {
    cin >> ii >> jj;
    cout << vec[ii][jj] << endl;
  }

  return 0;
}