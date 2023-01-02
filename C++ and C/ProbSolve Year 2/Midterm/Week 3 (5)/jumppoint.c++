#include<iostream>
#include <vector>
using namespace std;

#define MAX_N  100000

int main(){
    int n,r;
    cin >> n >> r;

    vector<int> point[MAX_N];
    for(int i=0;i<n;i++){
        vector<int> x_y;
        int x,y;
        cin >> x >> y;
        x_y.push_back(x);
        x_y.push_back(y);
    }
    return 0;
}