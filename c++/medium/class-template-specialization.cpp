// SUBDOMAINS: Other Concepts

#include <iostream>
using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T>
struct Traits;

const string data_f[3] = {"apple", "orange", "pear"};
const string data_c[3] = {"red", "green", "orange"};

template <>
class Traits<Fruit> {
 public:
  static string name(int i) {
    if (i < 0 || i > 2) return "unknown";
    return data_f[i];
  }
};

template <>
class Traits<Color> {
 public:
  static string name(int i) {
    if (i < 0 || i > 2) return "unknown";
    return data_c[i];
  }
};

int main() {
  int t = 0;
  std::cin >> t;

  for (int i = 0; i != t; ++i) {
    int index1;
    std::cin >> index1;
    int index2;
    std::cin >> index2;
    cout << Traits<Color>::name(index1) << " ";
    cout << Traits<Fruit>::name(index2) << "\n";
  }
}
