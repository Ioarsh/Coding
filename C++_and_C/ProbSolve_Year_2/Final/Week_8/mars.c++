#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX_N 100000

int n;
vector<string> word;
vector<long long> answer;
int max_weight[MAX_N];
long long ans=0;
long long ans_index;

void read_input(){
    cin >> n;
    for(int i=0;i<n;i++){
        string temp;
        cin >> temp;
        word.push_back(temp);
    }
}


long long choose(int index){
    // if(index==0){
    //     max_weight[index]=schedule[index][2];
    //     return max_weight[index];
    // }
    // int i=-1;
    // int max_l=0;
    // for(int j=0;j<index;j++){
    //     if(max_weight[j]>max_l && schedule[j][1]<=schedule[index][0]){
    //         max_l=max_weight[j];
    //         i=j;
    //     }
    // }
    // if(i==-1){
    //     max_weight[index]=schedule[index][2];
    // }
    // else{
    //     max_weight[index]=schedule[index][2]+max_weight[i];
    // }
    // return max_weight[index];
}

int main(void){
    read_input();
    // for(int i=0;i<n;i++){
    //     long long res=choose(i);
    //     if(res>ans){
    //         ans=res;
    //         ans_index=i;
    //     }
    // }
    // cout << ans << '\n';
    // // for(int i=0;i<n;i++){
    // //     cout << i << ' ' << max_weight[i] << "\n";
    // // }
    // for(int i=ans_index;i>=0;i--){
    //     if(max_weight[i]==ans){
    //         answer.push_back(i+1);
    //         ans-=schedule[i][2];
    //     }
    //     if(ans==0){
    //         break;
    //     }
    // }
    // reverse(answer.begin(),answer.end());
    // cout << answer.size() << "\n";
    // for(auto i: answer){
    //     cout << i << ' ';
    // }
}