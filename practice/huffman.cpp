#include <bits/stdc++.h>
using namespace std;

struct Char{
  char cr;
  int freq;
  int code;
};

class greaterCheck{
  public:
    int operator() (Char a, Char b){
      return a.freq > b.freq;
    }
};

class lowerCheck{
  public:
    int operator()(Char a, Char b){
      return a.freq < b.freq;
    }
};

int main(){
  vector<Char> vc;
  for(int i = 0; i < 5; i++){
    Char c;
    cout << "Enter character and frequency" << endl;
    cin >> c.cr >> c.freq;
    vc.push_back(c);
  }
  priority_queue<Char, vector<Char>, greaterCheck> minHeap;
  cout << "M" << endl;
  for(Char c : vc){
    minHeap.push(c);
  }
  int x = minHeap.size();
  priority_queue<Char, vector<Char>, lowerCheck> maxHeap;
  for(int i = 0; i < x; i++){
    int v = 0;
    v += minHeap.top().freq;
    maxHeap.push(minHeap.top());
    minHeap.pop();
    i++;
    v += minHeap.top().freq;
    maxHeap.push(minHeap.top());
    minHeap.pop();
    i++;
    Char c;
    c.cr = '\0';
    c.freq = v;
    maxHeap.push(c);
  }
  x = maxHeap.size();
  int prev = 1;
  for(int i = 1; i <= x; i++){
    cout << maxHeap.top().cr << " " << maxHeap.top().freq << endl;
    if(maxHeap.top().cr != '\0'){
      prev = prev*10;
      prev += (i%2);
      cout << "Code for " << maxHeap.top().cr << " is " << prev << endl;
    }
    maxHeap.pop();
  }
  return 0;
}

