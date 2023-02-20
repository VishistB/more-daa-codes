#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int low, int high, int s){
  int mid = (low + high) / 2;
  if(low > high) return -1;
  if(arr[mid] == s) return mid;
  else if(s < arr[mid]){
    return binarySearch(arr, low, mid-1, s);
  }
  else if(s > arr[mid]){
    return binarySearch(arr, mid+1, high, s);
  }
  return 0;
}

int main(){
  vector<int> xv;
  for(int i = 0; i < 10; i++){
    xv.push_back(i);
  }
  int s;
  cout << "Enter search element" << endl;
  cin >> s;
  int ind = binarySearch(xv, 0, xv.size() - 1, s);
  cout << "Found at Index = " << ind << endl;
  return 0;
}
