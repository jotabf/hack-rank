// SUBDOMAINS: Strings

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <sstream>
#include <vector>
using namespace std;

inline void remover_char(string &line, char c) {
  line.erase(remove(line.begin(), line.end(), c), line.end());
}

inline string str_sum(string &a, const string &b) { return a + b; }

int main() {
  int n, q, i;
  string line;
  vector<string> hrml;
  vector<string> qury;
  vector<string> tags;
  map<string, string> m;
  string tag, ch, attr, val, key;

  cin >> n >> q;

  cin.ignore();

  for (i = 0; i < n; i++) {
    getline(cin, line);
    hrml.push_back(line);
  }

  for (i = 0; i < q; i++) {
    getline(cin, line);
    qury.push_back(line);
  }

  for (i = 0; i < n; i++) {
    line = hrml[i];

    // Pre-processing
    remover_char(line, '\"');
    remover_char(line, '>');

    if (line.substr(0, 2) == "</") {
      tags.pop_back();
    } else {
      istringstream iss(line);

      iss >> tag;
      tag = tag.substr(1);

      if (tags.empty()) {
        tags.push_back(tag);
      } else {
        tags.push_back("." + tag);
      }

      key = accumulate(tags.begin(), tags.end(), std::string(), str_sum);

      while (iss >> attr >> ch >> val) {
        m[key + "~" + attr] = val;
      }
    }
  }

  for (i = 0; i < q; i++) {
    line = qury[i];
    
    if(m.find(line) == m.end()){
      cout << "Not Found!" << endl;
    } else {
      cout << m[line] << endl;
    }

  }

  return 0;
}