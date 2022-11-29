#include<iostream>
int main(){
    int n,k;
    std::cin >> n >> k;
    int* player = new int[n];
    for(int i=0;i<n;i++){
        std::cin >> player[i];
    }
    return 0;
}