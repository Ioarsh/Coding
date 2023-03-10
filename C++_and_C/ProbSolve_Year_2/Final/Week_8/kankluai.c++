#include<iostream>
#include<vector>
using namespace std;
#define MAX_N 100000

vector<int> score;
int max_score[MAX_N];
int ans=0;
int n;

void read_input(){
    cin >> n;
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        score.push_back(temp);
        max_score[i]=-1;
    }
}

int elephant(int i){
    if(i==0 || i==1){
        max_score[i]=0;
        return 0;
    }
    int index=0;
    int max_jump=0;
    for(int j=i-3;j>i-6;j--){
        if(j<0){
            break;
        }
        if(max_score[j]>max_jump){
            max_jump=max_score[j];
            index = j;
        }
    }
    max_score[i]=score[i]+max_score[index];
    return max_score[i];
}

int main(void){
    read_input();
    for(int i=0;i<n;i++){
        int res=elephant(i);
        if(res>ans){
            ans=res;;
        }
    }
    cout << ans;
}

/// A[i]=P[i]+max A[j] (j=i-3 to 1)
