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
  Workshops* ws;
};

Available_Workshops* initialize(int start_time[], int duration[], int n) {
  Available_Workshops* aws = new Available_Workshops[1];
  aws->ws = new Workshops[n];

  aws->n = n;
  for (int i = 0; i < n; i++) {
    aws->ws[i].start_time = start_time[i];
    aws->ws[i].duration = duration[i];
    aws->ws[i].end_time = start_time[i] + duration[i];
  }

  return aws;
}

int CalculateMaxWorkshops(Available_Workshops* ptr) {
  int count = 0;
  list<int> sched;

  for (int i = 0; i < ptr->n; i++) {
    if (sched.empty()) {
      sched.push_back(ptr->ws[i].start_time);
      sched.push_back(ptr->ws[i].end_time);
      count++;
      cout << "Empty case " << sched.front() << " "<< sched.back() << endl;
    } else {
      if (sched.front() == ptr->ws[i].end_time) {
        sched.pop_front();
        sched.push_front(ptr->ws[i].start_time);
        count++;
        continue;
      } else if (ptr->ws[i].end_time < sched.front()) {
        cout << "Front case [2] " << sched.front() <<" " <<ptr->ws[i].end_time << endl;
        sched.push_front(ptr->ws[i].end_time);
        sched.push_front(ptr->ws[i].start_time);        
        count++;
        continue;
      } else if (sched.back() == ptr->ws[i].start_time) {
        sched.pop_back();
        sched.push_back(ptr->ws[i].start_time);
        cout << "Back case 1" << endl;
        count++;
        continue;
      } else if (ptr->ws[i].start_time > sched.back() ) {
        sched.push_back(ptr->ws[i].start_time);
        sched.push_back(ptr->ws[i].end_time);
        cout << "Back case [2] " << sched.back() <<" " <<ptr->ws[i].start_time << endl;
        count++;
        continue;
      }
      list<int>::iterator it = sched.begin();
      list<int>::iterator it2;
      ++it;
      for (; it != sched.end(); ++it) {
        it2 = std::next(it);
        if (*it >= ptr->ws[i].start_time && *it2 <= ptr->ws[i].end_time) {
          if (*it == ptr->ws[i].start_time) {
            *it = ptr->ws[i].end_time;
          } else {
            sched.insert(it, ptr->ws[i].start_time);
          }
          if (*it2 == ptr->ws[i].end_time) {
            *it2 = ptr->ws[i].start_time;
          } else {
            sched.insert(it2, ptr->ws[i].end_time);
          }
          if (*it > *it2) {
            sched.erase(it);
            sched.erase(it2);
          }
          count++;
        }
        it++;
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
