#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
const int MAX_N = 100000;

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

  vector<int> subset;

  for(int i=0;i<n;i++){
        auto job = interval[i];
        bool isCompatible = true;
        
        for(auto jobIndex : subset)
        {
            if(job.second > interval[jobIndex].first &&
               job.first < interval[jobIndex].second)
            {
                isCompatible = false;
                break;
            }
        }
    
        if(isCompatible)
            subset.push_back(i);
  }

  cout << subset.size() << '\n';
}