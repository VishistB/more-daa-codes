#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Item{
  int weight;
  int value;
};

bool comp(Item& i1, Item& i2){
  return (((double)i1.value)/i1.weight) < (((double)i2.value)/i2.weight);
}

int main(){
  vector<Item> items;
  int x;
  cout << "Enter maximum knapsack size: ";
  cin >> x;
  for(int i = 0; i < 5; i++){
    Item it;
    cout << i + 1 << " item : ";
    cin >> it.value >> it.weight;
    items.push_back(it);
  }
  sort(items.begin(), items.end(), &comp);
  vector<Item> included;
  int curW = 0;
  for(Item a : items){
    if(curW < x){
      curW += a.weight;
      included.push_back(a);
    }else{
      curW += a.weight * (((double)a.value)/a.weight);
      a.weight *= (((double)a.value)/a.weight);
      included.push_back(a);
    }
  }
  for(Item b : included){
    cout << b.value << " - " << b.weight << endl;
  }
  return 0;
}
