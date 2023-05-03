#include <iostream>
using namespace std;

template <bool a, bool... d>
int reversed_binary_value() {
  if constexpr (sizeof...(d) > 0) {
    return (reversed_binary_value<d...>() << 1) + a;
  } else {
    return a;
  }
}

template <int n, bool... digits>
struct CheckValues {
  static void check(int x, int y) {
    CheckValues<n - 1, 0, digits...>::check(x, y);
    CheckValues<n - 1, 1, digits...>::check(x, y);
  }
};

template <bool... digits>
struct CheckValues<0, digits...> {
  static void check(int x, int y) {
    int z = reversed_binary_value<digits...>();
    std::cout << (z + 64 * y == x);
  }
};

int main() {
  int t;
  std::cin >> t;

  for (int i = 0; i != t; ++i) {
    int x, y;
    cin >> x >> y;
    CheckValues<6>::check(x, y);
    cout << "\n";
  }
}
