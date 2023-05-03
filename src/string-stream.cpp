#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<int> parseInts(string str) {
  int num;
  char com;
  vector<int> vec;
  stringstream ss(str);
  while (ss >> num) {
    vec.push_back(num);
    ss >> com;
  }
  return vec;
}

int main() {
  string str;
  cin >> str;
  vector<int> integers = parseInts(str);
  for (int i = 0; i < integers.size(); i++) {
    cout << integers[i] << "\n";
  }

  return 0;
}