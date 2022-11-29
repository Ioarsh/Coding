#include<iostream>
using namespace std;
int main(){
    int n,k,t,count=0,j=1;
    cin >> n >> k >> t;
    int* check = new int[n];
    for(int i=0;i<n;i++){
        check[i]=0;
    }
    check[0]=1;
    for(int i=0;i<n;i++){
        j=j+k;
        if(j>n){j=j-n;}
        check[j-1]=1;
        if(j==1 || j==t){break;}
    }
    for(int i=0;i<n;i++){
        if(check[i]==1){count++;}
    }
    cout << count << endl;
}