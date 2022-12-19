#include<iostream>
#include<cstring>
#include<list>
using namespace std;
list<int> x;
int main(){
    int M;
    cin >> M;
    for(int i=0; i<M;i++){
        string command;
        cin >> command;
        if((command.compare("li"))==0){
            int num;
            cin >> num;
            x.push_front(num);
        }
        else if((command.compare("ri"))==0){
            int num;
            cin >> num;
            x.push_back(num);
        }
        else if((command.compare("lr"))==0){
            x.push_back(x.front());
            x.pop_front();
        }
        else if((command.compare("rr"))==0){
            x.push_front(x.back());
            x.pop_back();
        }
    }
    for(list<int>::iterator itr = x.begin(); itr != x.end(); itr++){
        cout << *itr << '\n';
    }
}