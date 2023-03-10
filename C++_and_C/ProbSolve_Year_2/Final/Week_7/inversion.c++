#include<iostream>
#include<vector>
using namespace std;
#define MAX_N 100000
vector<long long> number;
long long n;
long long ans=0;

void read_input(){
    cin >> n;
    for(long long i=0;i<n;i++){
        long long temp;
        cin >> temp;
        number.push_back(temp);
    }
}

void print_vector(){
    for(long long i=0;i<n;i++){
        cout << number[i] << ' ';
    }
    cout << '\n';
}

void merge(long long left,long long mid,long long right){

    long long i=left,j=mid+1,k=0;
    long long count=0;
    int temp[MAX_N];

    while((i<=mid) && (j<=right)){
        if(number[i]<=number[j]){
            temp[k++]=number[i++];
            ans+=count;
        }
        else{
            temp[k++]=number[j++];
            count++;
        }
    }

    while(i<=mid){
        temp[k++]=number[i++];
        ans+=count;
    }

    while(j<=right){
        temp[k++]=number[j++];
    }

    for(long long i=0;i<k;i++){
        number[left+i]=temp[i];
    }
}


void mergeSort(long long left,long long right){
    long long mid;
    if(left < right) {
        mid = (left+right) / 2;
        mergeSort(left,mid);
        mergeSort(mid+1,right);
        merge(left,mid,right);
    }
}


int main(){
    read_input();
    mergeSort(0,n-1);
    cout << ans;
}