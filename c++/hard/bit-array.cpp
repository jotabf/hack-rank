#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  unsigned long long n, s, p, q;
  unsigned long long mod = pow(2, 31);
  unsigned long long a = 0, prev;
  unsigned long long count = 1;
  unsigned long long i;

  cin >> n >> s >> p >> q;

  prev = a = s % mod;
  for (i = 1; i < n; i++) {
    a = (a * p + q) % mod;
    if (a != prev) {
      count++;
    } else {
      break;
    }
    prev = a;
  }
  cout << count << endl;

  return 0;
}