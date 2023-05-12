// SUBDOMAINS: STL

#include <deque>
#include <iostream>
using namespace std;

void printKMax(int arr[], int n, int k) {
  deque<int> dq;
  int aux, i;
  int max = INT32_MIN;

  for (i = 0; i < k; i++) {
    dq.push_back(arr[i]);
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  cout << max << " ";
  for (i = k; i < n; i++) {
    aux = dq.front();
    dq.pop_front();
    dq.push_back(arr[i]);

    if (arr[i] > max) {
      max = arr[i];
      cout << max << " ";
    } else if (aux == max) {
      max = INT32_MIN;
      for (auto num : dq) {
        if (num > max) {
          max = num;
        }
      }
      cout << max << " ";
    } else {
      cout << max << " ";
    }
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t > 0) {
    int n, k;
    cin >> n >> k;
    int i;
    int arr[n];
    for (i = 0; i < n; i++) cin >> arr[i];
    printKMax(arr, n, k);
    t--;
  }
  return 0;
}