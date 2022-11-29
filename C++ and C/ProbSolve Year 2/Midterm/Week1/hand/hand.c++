#include<iostream>
int main(){
    int n=0,max=1;
    std::cin >> n ;
    int* a = new int[n];
    int* check = new int[n];
    for(int i=0;i<n;i++){
        std::cin >> a[i];
        check[i]=0;
    }
    for(int i=0;i<n;i++){
        int j=a[i],sum=1;
        if(check[i]==1){continue;}
        while(j!=i+1){
            check[j-1]=1;
            j=a[j-1];
            sum+=1;
        }
        if(sum>max){max=sum;}
    }
    std::cout << max << std::endl;
    return 0;
}