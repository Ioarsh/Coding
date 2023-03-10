#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
#define MAX_N 2000000
// vector<vector<int> > ans;
vector<int> number;
int n;

void read_input(){
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        number.push_back(temp);
    }
}

void print_vector(){
    for(int i=0;i<n;i++){
        if(i==0)
            cout << number[i];
        else
            cout << ' ' << number[i];
    }
    cout << '\n';
}

void merge(int left,int mid,int right){

    int i=left,j=mid+1,k=0;
    int temp[MAX_N];

    while((i<=mid) && (j<=right)){
        if(number[i]<=number[j]){
            temp[k++]=number[i++];
        }
        else{
            temp[k++]=number[j++];
        }
    }

    while(i<=mid){
        temp[k++]=number[i++];
    }

    while(j<=right){
        temp[k++]=number[j++];
    }

    for(int i=0;i<k;i++){
        number[left+i]=temp[i];
    }
}


void mergeSort(int left,int right){
    int mid;
    if(left < right) {
        mid = (left+right) / 2;
        mergeSort(left,mid);
        mergeSort(mid+1,right);
        merge(left,mid,right);
    }
}


int main(){
    time_t start,end;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int i=0;
    while(cin>>n && n){
        read_input();
        mergeSort(0,n-1);
        // sort(number.begin(),number.end());
        print_vector();
        number.clear();
        i++;
    }
}