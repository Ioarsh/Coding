#include<iostream>
int main(){
    int n,k,count=0;
    std::cin >> n >> k;
    double* player = new double[n];
    for(int i=0;i<n;i++){
        std::cin >> player[i];
    }
    double min=player[0];
    for(int i=0;i<n;i++){
        if(player[i]<min){min=player[i];}
    }
    double out=min*k;
    for(int i=0;i<n;i++){
        if(player[i]*(k-1)-out<0){count++;}
    }
    std::cout << count << std::endl;
    return 0;
}