#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Activity{
  int index;
  float startTime;
  float finishTime;
};

bool activity_sort(Activity& a1, Activity& a2){
  return a1.finishTime < a2.finishTime;
}

int main(){
  int n = 0;
  cout << "Enter the number of activities: ";
  cin >> n;
  vector<Activity> activities;
  for(int i = 0; i < n; i++){
    Activity a;
    cout << "Enter start time and end time for Activity " << (i+1) << endl;
    a.index = i+1;
    cin >> a.startTime >> a.finishTime;
    if(a.startTime > a.finishTime){i--;continue;}
    activities.push_back(a);
  }
  sort(activities.begin(), activities.end(), &activity_sort);
  for(Activity a: activities){
    cout << a.index << " -> " << a.startTime << " : " << a.finishTime << endl;
  }
  // Check
  cout << "-------------------------------------------------" << endl;
  vector<Activity> included;
  for(int i = 0; i < activities.size(); i++){
    if(included.size() > 0){
      if(included[included.size() - 1].finishTime <= activities[i].startTime ){
        included.push_back(activities[i]);
      }
    }else{
      included.push_back(activities[i]);
    }
  }
  for(Activity a: included){
    cout << a.index << " -> " << a.startTime << " : " << a.finishTime << endl;
  }
}
