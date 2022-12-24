#include<iostream>
#include<list>
#include<cstdlib>
using namespace std;
int main(){
    int n;
    list<int> trash;
    cin >> n;
    int *e=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        int p;
        cin >> p >> e[i];
    }
    int lowestprice_e=e[n-1];
    for(int i=n-1;i>-1;i--){
        if(lowestprice_e<e[i]){
            lowestprice_e=e[i];
        }
        else if(lowestprice_e>e[i]){
            trash.push_front(i);
        }
    }
    cout << trash.size() << '\n';
}