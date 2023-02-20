#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Job{
  int profit;
  int id;
  int time;
};

bool compare(Job& j1, Job& j2){
  if(j1.profit > j2.profit) return true;
  return false;
}

int main(){
  vector<Job> jobs;
  int totalTime;
  cout << "Enter total time available : ";
  cin >> totalTime;
  for(int i = 0; i < 5; i++){
    Job jb;
    jb.id = i + 1;
    cout << jb.id << ": ";
    cin >> jb.profit >> jb.time;
    jobs.push_back(jb);
  }
  sort(jobs.begin(), jobs.end(), &compare);
  int t = 0;
  int i = 0;
  vector<Job> included;
  while(t < totalTime){
    included.push_back(jobs[i]);
    t += jobs[i].time;
    i++;
  }
  for(int i = 0; i < included.size(); i++){
    cout << included[i].id << " : " << included[i].profit << " - " << included[i].time << endl;
  }
  cout << "Total Time: " << totalTime << endl;
  return 0;
}
