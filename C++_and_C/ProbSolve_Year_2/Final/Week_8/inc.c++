#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX_N 1000000
#define MAX_N_NEG -1000000

vector<int> number;
vector<int> answer;
int max_length[MAX_N];
int n;
int ans=0;
int ans_index;

int length(int index){
    if(index==0){
        max_length[index]=1;
        return 1;
    }
    int i=-1;
    int max_l=0;
    for(int j=0;j<index;j++){
        if(max_length[j]>max_l && number[j]<number[index]){
            max_l=max_length[j];
            i=j;
        }
    }
    if(i==-1){
        max_length[index]=1;
    }
    else{
        max_length[index]=1+max_length[i];
    }
    return max_length[index];
}

void read_input(){
    cin >> n;
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        number.push_back(temp);
    }
}

int main(void){
    read_input();
    for(int i=0;i<n;i++){
        int res=length(i);
        if(res>ans){
            ans=res;
            ans_index=i;
        }
    }
    // for(int i=0;i<n;i++){
    //     cout << i << ' ' << max_length[i] << "\n";
    // }
    cout << ans << '\n';
    for(int i=ans_index;i>=0;i--){
        if(max_length[i]==ans){
            answer.push_back(number[i]);
            ans--;
        }
        if(ans==0){
            break;
        }
    }
    reverse(answer.begin(),answer.end());
    for(auto i: answer){
        cout << i << ' ';
    }
}