#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
#define MAX_N 1000000

int n,c,k;
int power_A[MAX_N];
int power_B[MAX_N];
int max_power_A[MAX_N];
int max_power_B[MAX_N];
int Best[MAX_N];
vector<int> answer;


void read_input(){
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> power_A[i] >> power_B[i];
        Best[i]=-1;
    }
}

int choose(int i, int numA, int numB){
    if (i == n-1) {
        Best[i]=min(power_A[i],power_B[i]);
        return Best[i];
    }
    if (Best[i] != -1) {
        return Best[i];
    }
    int c_A = choose(i+1, numA+1, numB) + power_A[i]; /////
    int c_B = choose(i+1, numA, numB+1) + power_B[i]; /////
    int result;
    if (numA > numB) {
        if(numA - numB < k)
            result = min(c_A, c_B);
        else
            result = c_B;
    }
    else if (numB > numA) {
        if(numB - numA < k)
            result = min(c_A, c_B);
        else
            result = c_A;
    }
    else {
        result = min(c_A, c_B);
    }
    Best[i] = result;
    return result;
}

int main(void){
    cin >> c;
    for(int i=0;i<c;i++){
        read_input();
        answer.push_back(choose(0,0,0));
    }
    for(int i=0;i<n;i++){
        cout << i << " " << Best[i] << '\n';
    }
    for(auto i: answer){
        cout << i << '\n';
    }
}








// // // 50%
// int choose(int index){
//     //Best[i] = min(A[i],B[i]) by abs(A-B)<k
//     //A[i]= P_A[i]+Best[i-1]
//     //B[i]= P_B[i]+Best[i-1]
//     if(index==0){
//         max_power_A[index]=power_A[index];
//         max_power_B[index]=power_B[index];
//         if(max_power_A[index]<max_power_B[index]){
//             BEST[index][0] = max_power_A[index];
//             BEST[index][1] += 1;
//         }
//         else{
//             BEST[index][0] = max_power_B[index];
//             BEST[index][2] += 1;
//         }
//         return BEST[index][0];
//     }
//     if(BEST[index-1][0]!=-1){
//         max_power_A[index]=power_A[index]+BEST[index-1][0];
//         max_power_B[index]=power_B[index]+BEST[index-1][0];
//     }
//     else{
//         int prev_best=choose(index-1);
//         max_power_A[index]=power_A[index]+prev_best;
//         max_power_B[index]=power_B[index]+prev_best;
//     }
//     BEST[index][1]=BEST[index-1][1];
//     BEST[index][2]=BEST[index-1][2];
//     // cout << "Round: " << index << '\n';
//     // cout << max_power_A[index] << '\n';
//     // cout << max_power_B[index] << '\n';
//     // cout << BEST[index][1]-BEST[index][2] << '\n';
//     if(BEST[index][1]>BEST[index][2]){
//         if(BEST[index][1]-BEST[index][2]>=k){
//             BEST[index][0] = max_power_B[index];
//             BEST[index][2] += 1;
//         }
//         else{
//             if(max_power_A[index]<max_power_B[index]){
//                 BEST[index][0] = max_power_A[index];
//                 BEST[index][1] += 1;
//             }
//             else{
//                 BEST[index][0] = max_power_B[index];
//                 BEST[index][2] += 1;
//             }
//         }
//     }
//     else if(BEST[index][1]<BEST[index][2]){
//         if(BEST[index][2]-BEST[index][1]>=k){
//             BEST[index][0] = max_power_A[index];
//             BEST[index][1] += 1;
//         }
//         else{
//             if(max_power_A[index]<max_power_B[index]){
//                 BEST[index][0] = max_power_A[index];
//                 BEST[index][1] += 1;
//             }
//             else{
//                 BEST[index][0] = max_power_B[index];
//                 BEST[index][2] += 1;
//             }
//         }
//     }
//     else{
//         if(max_power_A[index]<max_power_B[index]){
//                 BEST[index][0] = max_power_A[index];
//                 BEST[index][1] += 1;
//         }
//         else{
//                 BEST[index][0] = max_power_B[index];
//                 BEST[index][2] += 1;
//         }
//     }
//     // cout << BEST[index][0] << '\n';
//     // cout << BEST[index][1] << '\n';
//     // cout << BEST[index][2] << '\n';
//     return BEST[index][0];
// }





