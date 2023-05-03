#define toStr(_STR_) #_STR_
#define io(_OUT_) cin >> _OUT_
#define FUNCTION(_NAME_, _OP_) \
  void _NAME_(int &a, int b) { \
    if (b _OP_ a) a = b;       \
  }
#define INF 2147483647
#define foreach(_VEC_, _I_) for (size_t _I_ = 0; _I_ < _VEC_.size(); _I_++)

#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  foreach (v, i) {
    io(v)[i];
  }
  int mn = INF;
  int mx = -INF;
  foreach (v, i) {
    minimum(mn, v[i]);
    maximum(mx, v[i]);
  }
  int ans = mx - mn;
  cout << toStr(Result =) << ' ' << ans;
  return 0;
}