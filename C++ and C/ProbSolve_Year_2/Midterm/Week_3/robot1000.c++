#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main(){
    int a[4]; //n=0,e=1,s=2,w=3
    int lost,x=0,y=0,ans;
    string command;
    getline(cin,command);
    cin >> lost;
    for(int i=0;i<4;i++){
        a[i]=0;
    }
    for(int i=0;i<command.size();i++){
        if(command[i]=='N'){
            a[0]++;
        }
        else if(command[i]=='E'){
            a[1]++;
        }
        else if(command[i]=='S'){
            a[2]++;
        }
        else{
            a[3]++;
        }
    }
    for(int i=0;i<lost;i++){
        if(a[0]==0 && a[1]==0 && a[2]==0 && a[3]==0){
            break;
        }
        else if(a[0]>a[2] && a[2]!=0){
            a[2]--;
        }
        else if(a[2]>a[0] && a[0]!=0){
            a[0]--;
        }
        else if(a[1]>a[3] && a[3]!=0){
            a[3]--;
        }
        else if(a[3]>a[1] && a[1]!=0){
            a[1]--;
        }
        else {
            int j=0;
            while(j!=4){
                if(a[j]!=0){
                    a[j]--;
                    break;
                }
                j++;
            }
        }
    }
    ans=abs(a[0]-a[2])+abs(a[1]-a[3]);
    ///cout << a[0] << ' ' << a[1] << ' ' << a[2] << ' ' << a[3] << '\n';
    cout << ans*2;

}