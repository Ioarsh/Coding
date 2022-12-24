#include<iostream>
#include<list>
#include<cstdlib>
using namespace std;


int main(){
    int  n;
    cin >> n;
    list<int> bead[n];
    for(int i=0;i<n;i++){
        bead[i].push_back(i+1);
    }
    for(int i=0;i<n-1;i++){
        int num,location;
        cin << num << location;
    }
    return 0;
}