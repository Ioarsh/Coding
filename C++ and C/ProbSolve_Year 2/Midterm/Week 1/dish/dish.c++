#include<iostream>
int main(){
    int n,a[300],max=0;
    std::cin >> n;
    for(int i=0;i<300;i++){
        a[i]=0;
    }
    for(int i=0;i<n;i++){
        int size;
        std::cin >> size;
        a[size-1]+=1;
    }
    for(int i=0;i<300;i++){
        if(a[i]>max){max=a[i];}
    }
    std::cout << max << std::endl;
}