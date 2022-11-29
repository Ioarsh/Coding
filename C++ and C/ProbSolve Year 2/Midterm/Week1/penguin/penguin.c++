#include<iostream>
using namespace std;
int main(){
    int n,count=0;
    cin >> n;
    int* a=new int[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i]>a[j]){
                count++;
            }
        }
    }
    cout << count << endl;
}