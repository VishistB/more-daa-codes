#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int low, int mid, int high){
  vector<int> v1, v2, v3;
  for(int i = low; i <= mid; i++){
    v1.push_back(v[i]);
  }
  for(int i = mid+1; i <= high; i++){
    v2.push_back(v[i]);
  }
  int a1 = v1.size();
  int a2 = v2.size();
  int i1 = 0, i2 = 0;
  while(i1 < a1 && i2 < a2){
    if(v1[i1] < v2[i2]){
      v3.push_back(v1[i1]);
      i1++;
    }else{
      v3.push_back(v2[i2]);
      i2++;
    }
  }
  while(i1 < a1) v3.push_back(v1[i1++]);
  while(i2 < a2) v3.push_back(v2[i2++]);
  for(int i = 0; i < v3.size(); i++){
    v[i+low] = v3[i];
  }
}

void mergeSort(vector<int> &v, int low, int high){
  if(low >= high) return;
  int mid = (low+high)/2;
  mergeSort(v, low, mid);
  mergeSort(v, mid+1, high);
  merge(v, low, mid, high);
  cout << low << " " << high << endl;
  for(int i = 0; i < v.size(); i++){
    cout << v[i] << ", ";
  }
  cout << endl;
  for(int i = 0; i < v.size(); i++){
    cout << v[i] << ", ";
  }
  cout << endl;
}

int main(){
  vector<int> inputs;

  inputs.push_back(12);
  inputs.push_back(1);
  inputs.push_back(14);
  inputs.push_back(19);
  inputs.push_back(5);

  mergeSort(inputs, 0, inputs.size() - 1);
  for(int i = 0; i < inputs.size(); i++){
    cout << inputs[i] << ", ";
  }
  cout << endl;
}
