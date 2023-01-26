#include<iostream>
#include<list>
using namespace std;
list<int> D[200],R[200];
int main(){
    int N;
    cin >> N;
    int now=0;
    while(N!=0){
        for(int i=1;i<=N;i++){
            R[now].push_back(i);
        }
        while(R[now].size()!=1){
            D[now].push_back(R[now].front());
            R[now].pop_front();
            R[now].push_back(R[now].front());
            R[now].pop_front();
        }
        now+=1;
        cin >> N;
    }
    for(int i=0;i<200;i++){
        if(R[i].size()==0){
            continue;
        }
        cout << "Discarded cards:";
        if(D[i].size()!=0){
            for(list<int>::iterator itr = D[i].begin(); itr != (D[i].end()); itr++){
                if(itr==--D[i].end()){break;}
                cout << ' ' << *itr << ",";
            }
            cout << ' ' << D[i].back() ;
        }
        cout << '\n';
        cout << "Remaining card: " << R[i].front();
        cout << '\n';
    }
    
}