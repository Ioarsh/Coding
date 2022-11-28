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
        int j=a[i];
        int sum=0;
        while(a[j-1]!=i+1){
            j=a[j-1];
            std::cout << j << "position" << std::endl;
            sum+=1;
        }
        if(sum>max){max=sum;}
    }
    std::cout << max << std::endl;
    return 0;
}