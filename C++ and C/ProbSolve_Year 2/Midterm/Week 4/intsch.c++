#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX_N = 100000;

int main(){
  int n;
  vector<vector<int> > interval;
  cin >> n;
  for(int i=0;i<n;i++){
    int s,f;
    cin >> s >> f;
    vector<int> time;
    time.push_back(s);
    time.push_back(f);
    interval.push_back(time);
  }
  sort(interval.begin(), interval.end(),
          [](vector<int>& a,vector<int>& b) {
  return a[1] < b[1];
  });
  cout << interval[0][0] << ' ' << interval[0][1] << '\n';
  cout << interval[1][0] << ' ' << interval[1][1] << '\n';
  cout << interval[2][0] << ' ' << interval[2][1] << '\n';
  cout << interval[3][0] << ' ' << interval[3][1] << '\n';
}