#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
    int l,n,max=0;
    cin >> l >> n;
    int **bridges=(int**)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++){
        int *b=(int*)malloc(sizeof(int*)*2);
        cin >> b[0] >> b[1];
        bridges[i]=b;
    }
    for(float i=0;i<l;i+=0.5){
        int count=0;
        for(int j=0;j<n;j++){
            if(i>bridges[j][0] && i<bridges[j][1]){
                count++;
            }
        }
        if(count>max){
            max=count;
        }
    }
    cout << max;
    return(0);
}