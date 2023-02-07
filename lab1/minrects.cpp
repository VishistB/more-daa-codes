#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solution(){
  long long int n, h, w;
  cin >> n >> h >> w;
  int high = n * h * w;
  int low = 1;
  while(low < high){
    int mid = (low + high) / 2;
    int val = (mid/w) * (mid/h);
    cout << "Val : " << val << endl << "Mid : " << mid << endl;
    if(val >= n){
      high = mid;
    }else{
      low = mid + 1;
    }
  }
  cout << high << endl;
}

int main(){
  int test_cases;
  cin >> test_cases;
  for(int i  = 0 ; i < test_cases; i++){
    solution();
  }
}
