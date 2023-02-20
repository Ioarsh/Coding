#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1000000;


int n;
vector<int> order;
vector<int> bestofthatround;
void read_input(){
    cin >> n;
    for(int i=0;i<n;i++){
        int dish;
        cin >> dish; dish--;
        order.push_back(dish);
        bestofthatround.push_back(0);
    }
}

int main(){
    read_input();
    int max_count=0;
    for(int i=0;i<n;i++){
        order[i] -= i;
        if(order[i]<0){
            order[i]+=n;
        }
        bestofthatround[order[i]]+=1;
    }
    for(int i=0;i<n;i++){
        if(bestofthatround[i]>max_count){
            max_count=bestofthatround[i];
        }
    }
    cout << max_count;
}