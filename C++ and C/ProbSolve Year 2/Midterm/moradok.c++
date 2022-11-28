#include<iostream>
int main(){
    int n,sum=0;
    std::cin >> n;
    for(int i=0;i<n;i++){
        int price;
        std::cin >> price;
        if(price>0){sum+=price;}
    }
    std::cout << sum << std::endl;
}