// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// #define MAX_N 200000
// int m;
// int t;
// vector<pair<int,int> > LR;
// vector<pair<int,int> > ans[MAX_N];
// int minimal=MAX_N;


// void read_input(int round)
// {
//     cin >> m;
//     pair<int,int> temp;
//     while(cin >> temp.first >> temp.second, !(temp.first==0 && temp.second==0)){
//         LR.push_back(temp);
//     }
// }

// void choose(int round){
//     int current_L=0,Reach=0;
//     int i;
//     while(Reach<m){
//         int temp_L=current_L;
//         int index=-1;
//         for(;i<LR.size();i++){
//             if(LR[i].first>current_L){
//                 break;
//             }
//             else if(LR[i].second >= temp_L){
//                 temp_L = LR[i].second;
//                 index = i;
//             }
//         }
//         if(index==-1){
//             break;
//         }
//         ans[round].push_back(LR[index]);
//         Reach = temp_L;
//         current_L = temp_L;
//     }
//     if(Reach>=m){
//         cout << ans[round].size() << '\n';
//         for(auto ele:ans[round]){
//             cout << ele.first << " " << ele.second << '\n';
//         }
//     }
//     else{
//         cout << '0' << '\n';
//     }
//     if(i!=t-1){
//             cout << '\n';
//     }
// }

// int main(){
//     cin >> t;
//     for(int i=0;i<t;i++){
//         LR.clear();
//         read_input(i);
//         sort(LR.begin(),LR.end());
//         choose(i);
//     }
// }

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX_N 200000
int m[MAX_N];
int t;
int Reach[MAX_N];
vector<pair<int,int> > LR;
vector<pair<int,int> > ans[MAX_N];


void read_input(int round)
{
    cin >> m[round];
    Reach[round]=0;
    pair<int,int> temp;
    while(cin >> temp.first >> temp.second, !(temp.first==0 && temp.second==0)){
        LR.push_back(temp);
    }
}

void choose(int round){
    int current_L=0;
    int i=0;
    while(Reach[round]<m[round]){
        int temp_L=current_L;
        int index=-1;
        for(;i<LR.size();i++){
            if(LR[i].first>current_L){
                break;
            }
            else if(LR[i].second >= temp_L){
                temp_L = LR[i].second;
                index = i;
            }
        }
        if(index==-1){
            break;
        }
        ans[round].push_back(LR[index]);
        Reach[round] = temp_L;
        current_L = temp_L;
    }
    // if(Reach[round]>=m[round]){
    //         cout << ans[round].size() << '\n';
    //         for(auto ele:ans[round]){
    //             cout << ele.first << " " << ele.second << '\n';
    //         }
    //     }
    //     else{
    //         cout << '0' << '\n';
    //     }
    //     if(i!=t-1){
    //             cout << '\n';
    //     }
}

int main(){
    cin >> t;
    for(int i=0;i<t;i++){
        LR.clear();
        read_input(i);
        sort(LR.begin(),LR.end());
        choose(i);
    }
    for(int i=0;i<t;i++){
        if(Reach[i]>=m[i]){
            cout << ans[i].size() << '\n';
            for(auto ele:ans[i]){
                cout << ele.first << " " << ele.second << '\n';
            }
        }
        else{
            cout << '0' << '\n';
        }
        if(i!=t-1){
            cout << '\n';
        }
    }
    // for(int i=0;i<t;i++){
    //     cout << Reach[i] << ' ' << m[i] << '\n';
    // }
}

// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// #define MAX_N 200000
// int m;
// int t;
// vector<pair<int,int> > LR;
// vector<pair<int,int> > ans[MAX_N];
// int minimal=MAX_N;

// bool compare(pair<int, int>& a, pair<int, int>& b) {
//     return a.first < b.first;
// }

// void read_input()
// {
//     cin >> m;
//     pair<int,int> temp;
//     while(cin >> temp.first >> temp.second, !(temp.first==0 && temp.second==0)){
//         LR.push_back(temp);
//     }
// }

// void choose(int round){
//    for(int i=0;i<LR.size();i++){
//     vector<pair<int,int> > temp;
//     if(LR[i].first > 0)
//         continue;
//     temp.push_back(LR[i]);
//     for(int j=i+1;j<LR.size();j++){
//         if(LR[j].second >= m && LR[j].second>temp[temp.size()-1].second && LR[j].first <=temp[temp.size()-1].second){
//             temp.push_back(LR[j]);
//         }
//         if(temp[temp.size()-1].second>=m)
//             break;
//     }
//     if(ans[round].empty()){
//         if(temp[temp.size()-1].second>=m){
//             for(auto ele:temp){
//                 ans[round].push_back(ele);
//             }
//         }
//     }
//     else{
//         if(temp[temp.size()-1].second>=m && temp.size()<ans[round].size()){
//             ans[round].clear();
//             for(auto ele:temp){
//                 ans[round].push_back(ele);
//             }
//         }
//     }
//    }
// }

// int main(){
//     cin >> t;
//     for(int i=0;i<t;i++){
//         LR.clear();
//         read_input();
//         sort(LR.begin(),LR.end(),compare);
//         choose(i);
//     }
//     for(int i=0;i<t;i++){
//         cout << ans[i].size() << '\n';
//         if(ans[i].size()!=0){
//             for(auto ele:ans[i]){
//                 cout << ele.first << ' ' << ele.second << '\n';
//             }
//             cout << '\n';
//         }
//         else
//             cout << '\n';
//     }
// }