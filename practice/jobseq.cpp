#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Job{
  int id, start, finish;
};

bool sortFunc(Job &a, Job &b){
  return a.finish < b.finish;
}

int main(){
  vector<Job> jobs;
  int totalTime = 0;
  for(int i = 0; i < 5; i++){
    Job jb;
    jb.id = i+1;
    cin >> jb.start >> jb.finish;
    jobs.push_back(jb);
  }
  sort(jobs.begin(), jobs.end(), &sortFunc);
  int t = 0;
  Job prev = jobs[0];
  vector<Job> included;
  included.push_back(prev);
  for(int i = 1; i < jobs.size(); i++){
    if(included[included.size() - 1].finish <= jobs[i].start){
      included.push_back(jobs[i]);
    }
  }
  for(Job jb : included){
    cout << jb.id << " : " << jb.start << " : " << jb.finish << endl;
  }
  return 0;
}
