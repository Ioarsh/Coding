#include<iostream>
#include<list>
#include<string>
using namespace std;
int main(){
    while(1){
        string allword;
        list<char> x;
        getline(cin,allword);
        if(allword==""){
            break;
        }
        list<char>::iterator itr=x.begin();
        for(int i=0;i<allword.size();i++){
            if(allword[i]=='['){
                itr = x.begin();
            }
            else if(allword[i]==']'){
                itr = x.end();
            }
            else{
                x.insert(itr,allword[i]);
            }
        }
        for(list<char>::iterator itr = x.begin(); itr != x.end(); itr++){
            cout << *itr;
        }
        cout << '\n';
    }
    return(0);
}
