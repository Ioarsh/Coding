#include<iostream>
#include<string>
#include<list>
using namespace std;
int main(){
    string command_2000;
    list<char> ans;
    getline(cin,command_2000);
    int direction=1; /// 1=N 2=E 3=S 4=W
    for(int i=0;i<command_2000.size();i++){
        switch(command_2000[i]){
            case 'N':
                if(direction==1){
                    ans.push_back('F');
                }
                else if(direction==2){
                    ans.push_back('R');
                    ans.push_back('R');
                    ans.push_back('R');
                    ans.push_back('F');
                    direction=1;
                }
                else if(direction==3){
                    ans.push_back('R');
                    ans.push_back('R');
                    ans.push_back('F');
                    direction=1;
                }
                else if(direction==4){
                    ans.push_back('R');
                    ans.push_back('F');
                    direction=1;
                }
                break;
            case 'E':
                if(direction==1){
                    ans.push_back('R');
                    ans.push_back('F');
                    direction=2;
                }
                else if(direction==2){
                    ans.push_back('F');
                }
                else if(direction==3){
                    ans.push_back('R');
                    ans.push_back('R');
                    ans.push_back('R');
                    ans.push_back('F');
                    direction=2;
                }
                else if(direction==4){
                    ans.push_back('R');
                    ans.push_back('R');
                    ans.push_back('F');
                    direction=2;
                }
                break;
            case 'S':
                if(direction==1){
                    ans.push_back('R');
                    ans.push_back('R');
                    ans.push_back('F');
                    direction=3;
                }
                else if(direction==2){
                    ans.push_back('R');
                    ans.push_back('F');
                    direction=3;
                }
                else if(direction==3){
                    ans.push_back('F');
                }
                else if(direction==4){
                    ans.push_back('R');
                    ans.push_back('R');
                    ans.push_back('R');
                    ans.push_back('F');
                    direction=3;
                }
                break;
            case 'W':
                if(direction==1){
                    ans.push_back('R');
                    ans.push_back('R');
                    ans.push_back('R');
                    ans.push_back('F');
                    direction=4;
                }
                else if(direction==2){
                    ans.push_back('R');
                    ans.push_back('R');
                    ans.push_back('F');
                    direction=4;
                }
                else if(direction==3){
                    ans.push_back('R');
                    ans.push_back('F');
                    direction=4;
                }
                else if(direction==4){
                    ans.push_back('F');
                }
                break;
            case 'Z':
                ans.push_back('Z');
                direction=1;
                break;

        }
    }
    for(list<char>::iterator itr = ans.begin(); itr != ans.end(); itr++){
        cout << *itr;
    }

}