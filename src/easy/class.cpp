#include <iostream>
#include <sstream>
using namespace std;

class Student {
  int _age;
  int _standard;
  string _first_name;
  string _last_name;

 public:
  Student() {}
  ~Student() {}

  void set_age(int age) { _age = age; }
  void set_standard(int standard) { _standard = standard; }
  void set_first_name(const string &first_name) { _first_name = first_name; }
  void set_last_name(const string &last_name) { _last_name = last_name; }

  int get_age() { return _age; }
  int get_standard() { return _standard; }
  string get_first_name() { return _first_name; }
  string get_last_name() { return _last_name; }

  string to_string() {
    return std::to_string(_age) + "," + _first_name + "," + _last_name + "," +
           std::to_string(_standard);
  }
};

int main() {
  int age, standard;
  string first_name, last_name;

  cin >> age >> first_name >> last_name >> standard;

  Student st;
  st.set_age(age);
  st.set_standard(standard);
  st.set_first_name(first_name);
  st.set_last_name(last_name);

  cout << st.get_age() << "\n";
  cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
  cout << st.get_standard() << "\n";
  cout << "\n";
  cout << st.to_string();

  return 0;
}