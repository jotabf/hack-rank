#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class Matrix {
 private:
 public:
  vector<vector<int>> a;

  Matrix() = default;
  Matrix(vector<vector<int>> in) : a(in) {}
  ~Matrix() {}

  Matrix operator+(const Matrix &other) {
    vector<vector<int>> result(a.size(), vector<int>(a[0].size()));

    for (int i = 0; i < a.size(); ++i) {
      for (int j = 0; j < a[0].size(); ++j) {
        result[i][j] = a[i][j] + other.a[i][j];
      }
    }

    return Matrix(result);
  }
};

int main() {
  int cases, k;
  cin >> cases;
  for (k = 0; k < cases; k++) {
    Matrix x;
    Matrix y;
    Matrix result;
    int n, m, i, j;
    cin >> n >> m;
    for (i = 0; i < n; i++) {
      vector<int> b;
      int num;
      for (j = 0; j < m; j++) {
        cin >> num;
        b.push_back(num);
      }
      x.a.push_back(b);
    }
    for (i = 0; i < n; i++) {
      vector<int> b;
      int num;
      for (j = 0; j < m; j++) {
        cin >> num;
        b.push_back(num);
      }
      y.a.push_back(b);
    }
    result = x + y;
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        cout << result.a[i][j] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
