#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Spell {
 private:
  string scrollName;

 public:
  Spell() : scrollName("") {}
  Spell(string name) : scrollName(name) {}
  virtual ~Spell() {}
  string revealScrollName() { return scrollName; }
};

class Fireball : public Spell {
 private:
  int power;

 public:
  Fireball(int power) : power(power) {}
  void revealFirepower() { cout << "Fireball: " << power << endl; }
};

class Frostbite : public Spell {
 private:
  int power;

 public:
  Frostbite(int power) : power(power) {}
  void revealFrostpower() { cout << "Frostbite: " << power << endl; }
};

class Thunderstorm : public Spell {
 private:
  int power;

 public:
  Thunderstorm(int power) : power(power) {}
  void revealThunderpower() { cout << "Thunderstorm: " << power << endl; }
};

class Waterbolt : public Spell {
 private:
  int power;

 public:
  Waterbolt(int power) : power(power) {}
  void revealWaterpower() { cout << "Waterbolt: " << power << endl; }
};

class SpellJournal {
 public:
  static string journal;
  static string read() { return journal; }
};
string SpellJournal::journal = "";

int LCS(const string &a, const string &b) {
  int m = a.size(), n = b.size();
  vector<vector<int> > vec(m + 1, vector<int>(n + 1, 0));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      vec[i + 1][j + 1] =
          (a[i] == b[j] ? vec[i][j] + 1 : max(vec[i + 1][j], vec[i][j + 1]));
    }
  }
  return vec[m][n];
}

void counterspell(Spell *spell) {
  if (Fireball *sp = dynamic_cast<Fireball *>(spell)) {
    sp->revealFirepower();
  } else if (Frostbite *sp = dynamic_cast<Frostbite *>(spell)) {
    sp->revealFrostpower();
  } else if (Thunderstorm *sp = dynamic_cast<Thunderstorm *>(spell)) {
    sp->revealThunderpower();
  } else if (Waterbolt *sp = dynamic_cast<Waterbolt *>(spell)) {
    sp->revealWaterpower();
  } else {
    cout << LCS(spell->revealScrollName(), SpellJournal::read()) << endl;
  }
}

class Wizard {
 public:
  Spell *cast() {
    Spell *spell;
    string s;
    cin >> s;
    int power;
    cin >> power;
    if (s == "fire") {
      spell = new Fireball(power);
    } else if (s == "frost") {
      spell = new Frostbite(power);
    } else if (s == "water") {
      spell = new Waterbolt(power);
    } else if (s == "thunder") {
      spell = new Thunderstorm(power);
    } else {
      spell = new Spell(s);
      cin >> SpellJournal::journal;
    }
    return spell;
  }
};

int main() {
  int T;
  cin >> T;
  Wizard Arawn;
  while (T--) {
    Spell *spell = Arawn.cast();
    counterspell(spell);
  }
  return 0;
}