#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Job{
  int profit;
  int time;
};

bool sortJob(Job a, Job b){
  if(a.profit > b.profit)
    return true;
  else if(a.profit == b.profit && a.time < b.time) return true;
  return false;
}

int main(){
  cout << "Enter the number of jobs that you want to sequence" << endl;
  int n;
  cin >> n;
  vector<Job> jobs;
  cout << "Enter the max size of gantt chart" << endl;
  int gtSize = n;
  cin >> gtSize;
  for(int i = 0; i < n; i++){
    Job j;
    cout << "Enter profit and estimated time for Job " << i << endl;
    cin >> j.profit >> j.time;
    jobs.push_back(j);
  }
  sort(jobs.begin(), jobs.end(), &sortJob);
  int ct = 0;
  int profit = 0;
  for(auto job: jobs){
    if(ct > gtSize) break;
    profit += job.profit;
    ct += job.time;
  }
  cout << "Net Profit: " << profit << " and Total Time Taken: " << ct << endl;
  cout << "Jobs exectuted: ";
  for(auto job: jobs){
    cout << " " << job.profit << ", ";
  }
  cout << endl;
  return 0;
}
