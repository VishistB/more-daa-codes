#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Char{
  char cr;
  int freq;
  string code;
};

class greaterCheck{
  public:
    int operator() (Char a, Char b)
    {
      return a.freq > b.freq;
    }
};

class lowerCheck{
  public:
    int operator() (Char a, Char b)
    {
      return a.freq < b.freq;
    }
};

int main(){
  priority_queue<Char, vector<Char>, greaterCheck> min;
  vector<Char> inp;
  for(int i = 0; i < 5; i++){
    Char t;
    cout << "Enter character and its frequency" << endl;
    cin >> t.cr >> t.freq;
    min.push(t);
  }
  priority_queue<Char, vector<Char>, greaterCheck> min2;
  int x = min.size();
  cout << x << endl;
  for(int i = 0; i < x; i++){
    Char t1 = min.top();
    min.pop();
    Char t2 = min.top();
    min.pop();
    min2.push(t1);
    min2.push(t2);
    Char tv;
    tv.freq = t1.freq + t2.freq;
  }
}
