// SUBDOMAINS: Other Concepts

#include <bits/stdc++.h>

using namespace std;

// Define the structs Workshops and Available_Workshops.
// Implement the functions initialize and CalculateMaxWorkshops
struct Workshops {
  int start_time;
  int duration;
  int end_time;

  bool operator<(const Workshops other) {
    return end_time < other.end_time;
  }
};

struct Available_Workshops {
  int n;
  vector<Workshops> ws;

  Available_Workshops(int num) : n(num) {
    ws.resize(num);
  }  
  ~Available_Workshops(){}  
};

Available_Workshops* initialize(int start_time[], int duration[], int n) {
  Available_Workshops *aws = new Available_Workshops(n);

  for (int i = 0; i < n; i++) {
    aws->ws[i].start_time = start_time[i];
    aws->ws[i].duration = duration[i];
    aws->ws[i].end_time = start_time[i] + duration[i];
  }

  return aws;
}

void print_ws(Available_Workshops* ptr){
  for (auto i : ptr->ws) {  
    std::cout << i.start_time << "-" << i.end_time << " ";
  }
  std::cout << std::endl;
}

int CalculateMaxWorkshops(Available_Workshops* ptr) {
  int count = 0, end = 0;
  std::sort(ptr->ws.begin(), ptr->ws.end());

  for (int i = 0; i < ptr->n; i++) {
    if(ptr->ws[i].start_time >= end){
      end = ptr->ws[i].end_time;
      count++;
    }
  }
  return count;
}

int main(int argc, char* argv[]) {
  int n;  // number of workshops
  cin >> n;
  // create arrays of unknown size n
  int* start_time = new int[n];
  int* duration = new int[n];

  for (int i = 0; i < n; i++) {
    cin >> start_time[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> duration[i];
  }

  Available_Workshops* ptr;
  ptr = initialize(start_time, duration, n);
  cout << CalculateMaxWorkshops(ptr) << endl;

  return 0;
}
