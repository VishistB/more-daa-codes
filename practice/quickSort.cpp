#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int pivot(vector<int> &v, int low, int high){
  int pvt = high;
  int i = high-1;
  while(i >= 0){
    cout << "i = " << i << endl;
    if(v[i] > v[pvt]){
      cout << "Exchanging with : " << v[i] << " t " << v[pvt] << endl;
      int k = v[i];
      v[i] = v[pvt];
      v[pvt] = k;
      cout << "Pivot index from  " << pvt << " to ";
      pvt = i;
      cout << pvt << endl;
    }
    i--;
  }
  cout << "Pivot: " << v[pvt] << endl;
  return pvt;
}

void quickSort(vector<int> &v, int low, int high){
  if(low >= high) return;
  int pvt = pivot(v, low, high);
  for(int i = 0; i < v.size(); i++){
    cout << v[i] << ", ";
  }
  cout << endl;
  quickSort(v, low, pvt-1);
  quickSort(v, pvt, high);
}

int main(){
  vector<int> input;
  input.push_back(12);
  input.push_back(1);
  input.push_back(14);
  input.push_back(19);
  input.push_back(5);
  input.push_back(13);
  input.push_back(12);
  input.push_back(23);

  quickSort(input, 0, input.size() - 1);
  cout << "-------------------------------------------------------------------" << endl;
  cout << "Final : ";
  for(int i = 0; i < input.size(); i++){
    cout << input[i] << ", ";
  }
  cout << endl;
};
