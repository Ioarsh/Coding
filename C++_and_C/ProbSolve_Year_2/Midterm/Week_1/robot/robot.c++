#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int x=0,y=0;
    string word;
    cin >> word;
    int n = word.length();
    char* letter = new char[n+1];
    strcpy(letter, word.c_str());
    for(int i=0;i<n;i++){
        if(letter[i]=='N'){
            y+=1;
        }
        else if(letter[i]=='S'){
            y-=1;
        }
        else if(letter[i]=='E'){
            x+=1;
        }
        else if(letter[i]=='W'){
            x-=1;
        }
        else if(letter[i]=='Z'){
            x=0;
            y=0;
        }
    }
    cout << x << " " << y << endl;
    return 0;
}