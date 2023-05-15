#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

struct Node {
  Node* next;
  Node* prev;
  int value;
  int key;
  Node(Node* p, Node* n, int k, int val)
      : prev(p), next(n), key(k), value(val){};
  Node(int k, int val) : prev(NULL), next(NULL), key(k), value(val){};
};

class Cache {
 protected:
  map<int, Node*> mp;              // map the key to the node in the linked list
  int cp;                          // capacity
  Node* tail;                      // double linked list tail pointer
  Node* head;                      // double linked list head pointer
  virtual void set(int, int) = 0;  // set function
  virtual int get(int) = 0;        // get function
};

void print_n(Node* head) {
  Node* aux = head;
  while (aux) {
    cout << "V[" << aux->key << "] = " << aux->value << " | ";
    aux = aux->next;
  };
  cout << endl;
}

class LRUCache : public Cache {
  int count;

 public:
  LRUCache(int capacity) : count(0) {
    Cache::cp = capacity;
    Cache::head = nullptr;
    Cache::tail = nullptr;
  }
  ~LRUCache() {}

  void reset_pos(int key) {
    if (count > 1) {
      Node* aux = mp[key];
      if (aux == tail) {
        tail = tail->prev;
        // Corta ligação anterior
        aux->prev->next = nullptr;
        aux->prev = nullptr;
        // Emenda ligação posterior
        aux->next = head;
        head->prev = aux;
        head = aux;
      } else if (aux != head) {
        aux->prev->next = aux->next;
        aux->next->prev = aux->prev;
        aux->next = head;
        head->prev = aux;
        head = aux;
      }
    }
  }

  void remove_tail() {
    Node* aux = tail;
    tail = tail->prev;
    tail->next = nullptr;
    mp.erase(aux->key);
    delete aux;
  }

  void set(int key, int value) {
    if (!mp.count(key)) {
      if (count == 0) {
        head = new Node(nullptr, nullptr, key, value);
        mp[key] = tail = head;
      } else {
        Node* aux = new Node(nullptr, head, key, value);
        mp[key] = head->prev = aux;
        head = aux;
      }
      if (count == cp) {
        remove_tail();
      }
      // print_n(head);
      if (count < cp) count++;
    } else {
      reset_pos(key);
      mp[key]->value = value;
    }
  }

  int get(int key) {
    if (mp.count(key)) {
      reset_pos(key);
      return mp[key]->value;
    }
    return -1;
  }
};

int main() {
  int n, capacity, i;
  cin >> n >> capacity;
  LRUCache l(capacity);
  for (i = 0; i < n; i++) {
    string command;
    cin >> command;
    if (command == "get") {
      int key;
      cin >> key;
      cout << l.get(key) << endl;
    } else if (command == "set") {
      int key, value;
      cin >> key >> value;
      l.set(key, value);
    }
  }
  return 0;
}
