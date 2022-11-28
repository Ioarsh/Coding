#include<iostream>
#include<cstdlib>
int main(){
    int n,max=1;
    std::cin >> n ;
    int* a = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        std::cin >> a[i];
    }
    for(int i=0;i<n;i++){
        int j=a[i],sum=1;
        while(j!=i+1){
            j=a[j-1];
            sum+=1;
        }
        if(sum>max){max=sum;}
    }
    std::cout << max << std::endl;
    return 0;
}