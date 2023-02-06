#include<iostream>
#include<vector>
using namespace std;
int k,n;
vector<vector<int> > contract;
vector<int> info;
void read_input(){
    cin >> k >> n;
    for(int i=0;i<k;i++){
        vector<int> con;
        int c,p,w;
        cin >> c,p,w;
        con.push_back(c);
        con.push_back(p);
        con.push_back(w);
        contract.push_back(con);
    }
}
int main(void){
    return 0;
}