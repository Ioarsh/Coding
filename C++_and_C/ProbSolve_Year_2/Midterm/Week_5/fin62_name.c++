#include<iostream>
#include<vector>
using namespace std;
string word;
string sentence;
int main(void){
    int count=0;
    int index_word=0;
    getline(cin,word);
    getline(cin,sentence);
    for(int i=0;i<sentence.length();i++){
        if(sentence[i]==word[index_word]){
            index_word++;
        }
        if(index_word==word.length()){
            count++;
            index_word=0;
        }
    }
    cout << count ;
    return 0;
}
