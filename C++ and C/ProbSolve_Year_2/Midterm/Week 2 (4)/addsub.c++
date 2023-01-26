#include<iostream>
#include<list>
using namespace std;
list<int> x;
int main(){
    int M;
    cin >> M;
    for(int i=0; i<M;i++){
        char A;
        cin >> A;
        int n;
        cin >> n;
        if(A=='I'){
            x.push_front(n);
        }
        if(A=='A'){
            x.push_back(n);
        }
        if(A=='D'){
            int count=1;
            for(list<int>::iterator itr = x.begin(); itr != x.end(); itr++){
                    if(count==n){
                        x.erase(itr);
                        break;
                    }
                    count++;
            }
        }
    }
    for(list<int>::iterator itr = x.begin(); itr != x.end(); itr++){
            cout << *itr << "\n";
    }
}