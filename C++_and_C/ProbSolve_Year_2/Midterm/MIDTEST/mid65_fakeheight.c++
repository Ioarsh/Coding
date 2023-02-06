#include<iostream>
#include<vector>
using namespace std;

vector<int> student;
vector<int> diff_height;
int n;
int left_index;
int right_index;
int max_different=0;

int find_sum(vector<int> diff_height){
    int sum=0;
    for(auto height:diff_height){
        sum+=height;
    }
    return sum;
}

int find_diff_height(vector<int> st){
    vector<int> diff_height;
    for(int i=0;i<n-1;i++){
        diff_height.push_back(abs(student[i]-student[i+1]));
    }
    return find_sum(diff_height);
}

int main(){
    int minimal;
    cin >> n;
    for(int i=0;i<n;i++){
        int st;
        cin >> st;
        student.push_back(st);
    }
    minimal=find_diff_height(student);
    for(int i=0;i<n-1;i++){
        int diff=abs(student[i]-student[i+1]);
        if(diff>max_different){
            max_different=diff;
            left_index=i;
            right_index=i+1;
        }
    }
    cout << minimal;
}