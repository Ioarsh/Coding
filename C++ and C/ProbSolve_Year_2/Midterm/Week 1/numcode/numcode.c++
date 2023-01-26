#include<iostream>
using namespace std;
int main(){
    int n,t;
    cin >> n >> t;
    int* data = new int[n];
    int* data_y_to_bi = new int[n];
    int* data_z_to_y = new int[n];
    for(int i=0;i<n;i++){
        cin >> data[i];
    }
    if(t==1){
        if(data[0]==n-1){data_y_to_bi[0]=0;}
        else{data_y_to_bi[0]=1;}
        for(int i=1;i<n;i++){
            if(data[i]==data[i-1]-1){data_y_to_bi[i]=0;}
            else{data_y_to_bi[i]=1;}
        }
    }
    else{
        data_z_to_y[0]=data[0];
        for(int i=1;i<n;i++){
            if(data[i]-2*data_z_to_y[i-1]>0){data_z_to_y[i]=data[i]-2*data_z_to_y[i-1];}
            else{data_z_to_y[i]=data[i]-data_z_to_y[i-1];}
        }
        if(data_z_to_y[0]==n-1){data_y_to_bi[0]=0;}
        else{data_y_to_bi[0]=1;}
        for(int i=1;i<n;i++){
            if(data_z_to_y[i]==data_z_to_y[i-1]-1){data_y_to_bi[i]=0;}
            else{data_y_to_bi[i]=1;}
        }
    }
    for(int i=0;i<n;i++){
        cout << data_y_to_bi[i] << endl;
    }
}