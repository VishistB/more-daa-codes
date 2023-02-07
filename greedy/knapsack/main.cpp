#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Item{
  int label;
  int weight;
  float ratio;
};

bool itemSort(Item& i1, Item& i2){
  return i1.ratio > i2.ratio;
}

int main(){
  vector<Item> items;
  cout << "Enter knapsack capacity: ";
  int cap;
  cin >> cap;
  int n = 0;
  cout << "Enter number of items : ";
  cin >> n;
  for(int i = 0; i < n; i++){
    cout << "[" << i << "]: \n";
    cout << "Value: ";
    int v;
    cin >> v;
    cout << "Weight: ";
    int w;
    cin >> w;
    Item it;
    it.label = v;
    it.weight = w;
    it.ratio = v/ (w * 1.0f);
    items.push_back(it);
  }
  sort(items.begin(), items.end(), &itemSort);
  for(Item i : items){
    cout << i.label << " : " << i.weight << " : " << i.ratio << endl;
  }
  int cur = 0;
  int curCap = 0;
  vector<Item> includedItems;
  while(items[cur].weight <= cap - curCap){
    curCap += items[cur].weight;
    includedItems.push_back(items[cur]);
  }
  cout << curCap << " is the capacity\n" << "Included Items" << endl;
  for(Item i : items){
    cout << i.label << " : " << i.weight << " : " << i.ratio << endl;
  }
  return 0;
}
