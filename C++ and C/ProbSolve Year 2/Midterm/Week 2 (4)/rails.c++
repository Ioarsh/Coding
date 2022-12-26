#include<iostream>
#include<list>
using namespace std;
int main(){
    list<string> ans;
    int n;
    while(cin>>n){
        if(n==0){
            break;
        }
        while(true){
            list<int> x;
            int first;
            cin >> first;
            if(first==0){
                break;
            }
            x.push_back(first);
            for(int i=0;i<n-1;i++){
                int coashes;
                cin >> coashes;
                x.push_back(coashes);
            }
            int can=1;
            list<int> s;
            for(int i =0;i<n;i++){
                s.push_front(i+1);
                while(!s.empty() && s.front()==x.front()){
                    s.pop_front();
                    x.pop_front();
                }
            }
            if(!s.empty()){
                can=0;
            }
            if(can){
                cout << "Yes" << '\n';
            }
            else{
                cout << "No" << '\n';
            }
        }
        cout << '\n';
    }
    return(0);
}