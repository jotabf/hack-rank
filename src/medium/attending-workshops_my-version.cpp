#include <bits/stdc++.h>

using namespace std;

// Define the structs Workshops and Available_Workshops.
// Implement the functions initialize and CalculateMaxWorkshops
struct Workshops {
  int start_time;
  int duration;
  int end_time;
};

struct Available_Workshops {
  int n;
  Workshops *ws;

  Available_Workshops(int num) : n(num) {
    ws = new Workshops[num];
  }  
  ~Available_Workshops(){
    delete[] ws;
  }
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

void print_list(list<int> mylist){
  for (auto i : mylist) {  
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

int CalculateMaxWorkshops(Available_Workshops* ptr) {
  int count = 0;
  list<int> sched = {0, INT32_MAX};

  for (int i = 0; i < ptr->n; i++) {
    ptr->ws[i].start_time;
    ptr->ws[i].end_time;

    list<int>::iterator it2, aux;
    for (list<int>::iterator it = sched.begin(); it != sched.end(); std::advance(it, 2)) {
      it2 = std::next(it);
      if(*it <= ptr->ws[i].start_time && ptr->ws[i].end_time <= *it2){
        if(*it == ptr->ws[i].start_time){
          *it = ptr->ws[i].end_time;
        } else {
          sched.insert(it2, ptr->ws[i].start_time);
        }
        if(*it2 == ptr->ws[i].end_time){
          *it2 =  ptr->ws[i].start_time;
        } else {
          sched.insert(it2, ptr->ws[i].end_time);
        } 
        if(*it2 < *it){
          aux = std::next(it2);
          sched.erase(it);
          sched.erase(it2);
          it = aux;
        }
        count++;
        print_list(sched);
      }
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

  delete[] ptr->ws;
  delete[] ptr;

  return 0;
}
