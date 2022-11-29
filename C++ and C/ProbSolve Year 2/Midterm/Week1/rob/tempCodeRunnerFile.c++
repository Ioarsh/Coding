#include<iostream>
int main(){
    int n,k,count=0;
    std::cin >> n >> k;
    float* player = new float[n];
    for(int i=0;i<n;i++){
        std::cin >> player[i];
    }
    int min=player[0];
    for(int i=0;i<n;i++){
        if(player[i]<min){min=player[i];}
    }
    for(int i=0;i<n;i++){
        player[i]=k/player[i];
        if(player[i]>1/(float)k){count++;}
    }
    std::cout << count << std::endl;
    return 0;
}