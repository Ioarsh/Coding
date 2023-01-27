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
  return p1.second < p2.second;
  });
}