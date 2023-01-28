#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(){
  int n;
  vector<pair<int,int>> interval;

  cin >> n;
  for(int i=0;i<n;i++){
    int s,f;
    cin >> s >> f;
    vector<int> time;
    interval.push_back(make_pair(s, f));
  }

  sort(interval.begin(), interval.end(),
          [](pair<int,int> p1, pair<int,int> p2) {
  return p1.first < p2.first;
  });

  int t=0;
  vector<pair<int,int>> Job_interval;
  for(int i=0;i<n;i++){
      Job_interval.push_back(make_pair(t,t+interval[i].second));
      t += interval[i].second;
  }

  int money=0;
  for(int i=0;i<n;i++){
    auto pair = Job_interval[i];
    ///cout << pair.second << ' ' << interval[i].first << " " << "this is it" << '\n';
    if((pair.second-interval[i].first)>10){
      money=max(money,(pair.second-interval[i].first-10)*1000);
    }
  }

  
  cout << money;
}