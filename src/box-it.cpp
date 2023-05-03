#include <bits/stdc++.h>

using namespace std;

class Box {
  int l;  // length
  int b;  // breadth
  int h;  // height

 public:
  Box();
  Box(int, int, int);
  Box(const Box&);

  ~Box() {}

  int getLength() { return l; };   // Return box's length
  int getBreadth() { return b; };  // Return box's breadth
  int getHeight() { return h; };   // Return box's height
  long long CalculateVolume();     // Return the volume of the box

  bool operator<(Box&);  // Overload operator < as specified
  friend ostream& operator<<(ostream&,
                             const Box&);  // Overload operator << as specified
};

// --- Box Methods definitions ---
Box::Box() : l(0), b(0), h(0){};

Box::Box(const Box& box) : l(box.l), b(box.b), h(box.h) {}

Box::Box(int length, int breadth, int height)
    : l(length), b(breadth), h(height) {}

long long Box::CalculateVolume() {
  return (long long)l * (long long)b * (long long)h;
}

bool Box::operator<(Box& box) {
  return l < box.l || b < box.b && l == box.l ||
         h < box.h && b == box.b && l == box.l;
}

ostream& operator<<(ostream& os, const Box& box) {
  os << box.l << " " << box.b << " " << box.h;
  return os;
}
// --- Box Methods definitions ---

void check2() {
  int n;
  cin >> n;
  Box temp;
  for (int i = 0; i < n; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      cout << temp << endl;
    }
    if (type == 2) {
      int l, b, h;
      cin >> l >> b >> h;
      Box NewBox(l, b, h);
      temp = NewBox;
      cout << temp << endl;
    }
    if (type == 3) {
      int l, b, h;
      cin >> l >> b >> h;
      Box NewBox(l, b, h);
      if (NewBox < temp) {
        cout << "Lesser\n";
      } else {
        cout << "Greater\n";
      }
    }
    if (type == 4) {
      cout << temp.CalculateVolume() << endl;
    }
    if (type == 5) {
      Box NewBox(temp);
      cout << NewBox << endl;
    }
  }
}

int main() { check2(); }