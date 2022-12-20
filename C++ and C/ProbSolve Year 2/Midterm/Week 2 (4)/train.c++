#include<iostream>
#include<list>
using namespace std;
list<int> x[100001];
int main(){
    int N;
    cin >> N;
    for(int i=0; i<N;i++){
        int F,S;
        char C;
        cin >> C >> F >> S;
        if(C=='N'){
            x[S].push_back(F);
        }
        else if(C=='M'){
            x[S].splice(x[S].end(),x[F]);
            x[F].clear();
        }
        
    }
    for(int i=0;i<100001;i++){
        if(x[i].size()==0){
            continue;
        }
        for(list<int>::iterator itr = x[i].begin(); itr != x[i].end(); itr++){
            cout << *itr << "\n";
        }
    }
}