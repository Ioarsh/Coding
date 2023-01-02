#include<iostream>
#include<cstdlib>
#include<list>
using namespace std;
int main(){
    list<int> winner;
    int n,max1=0,max2=0,max3=0,max4=0,winnerA,winnerB;
    cin >> n;
    int *con=(int*)malloc(sizeof(int)*((4*n)+1));
    con[0]=-1;
    for(int i=1;i<=4*n;i++){
        cin >> con[i];
    }
    for(int i=1;i<=n;i++){
        if(con[i]>con[max1]){
            max1=i;
        }
    }
    for(int i=n+1;i<=2*n;i++){
        if(con[i]>con[max2]){
            max2=i;
        }
    }
    for(int i=(2*n)+1;i<=3*n;i++){
        if(con[i]>con[max3]){
            max3=i;
        }
    }
    for(int i=(3*n)+1;i<=4*n;i++){
        if(con[i]>con[max4]){
            max4=i;
        }
    }
    if(con[max1]>con[max2]){
        winnerA=max1;
        winner.push_back(max2);
    }
    else{
        winnerA=max2;
        winner.push_back(max1);
    }
    if(con[max3]>con[max4]){
        winnerB=max3;
        winner.push_back(max4);
    }
    else{
        winnerB=max4;
        winner.push_back(max3);
    }
    if(con[winnerA]>con[winnerB]){
        winner.push_front(winnerB);
        winner.push_front(winnerA);
    }
    else{
        winner.push_front(winnerA);
        winner.push_front(winnerB);
    }
    for(list<int>::iterator itr = winner.begin(); itr != winner.end(); itr++){
        cout << *itr << ' ';
    }
    return 0;
}