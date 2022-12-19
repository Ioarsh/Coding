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
            list<int>::iterator begin = x.begin();
            x.push_back(*begin);
            x.erase(begin);
        }
        else if((command.compare("rr"))==0){
            list<int>::iterator e = x.end();
            e--;
            int end = x.back();
            x.push_front(end);
            x.erase(e);
        }
    }
    for(list<int>::iterator itr = x.begin(); itr != x.end(); itr++){
        cout << *itr << '\n';
    }
}