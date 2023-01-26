#include<iostream>
using namespace std;

int n,m;
char map[30][30];
bool visited[30][30];
int good2=0,good1=0,count_all=0;
bool both=false;

void read_input(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
            visited[i][j]=false;
        }
    }
}

void check(int row,int col,char s){
    if(visited[row][col]){
        return;
    }
    visited[row][col]=true;
    count_all++;
    if(map[row][col] == '*' && s=='$' ){
        both=true;
    }
    else if(map[row][col]=='$' && s=='*'){
        both=true;
    }
    if(row-1>=0 && map[row-1][col]!='#' && visited[row-1][col]==false){
        check(row-1,col,s);
    }
    if(row+1<n && map[row+1][col]!='#' && visited[row+1][col]==false){
        check(row+1,col,s);
    }
    if(col+1<m && map[row][col+1]!='#' && visited[row][col+1]==false){
        check(row,col+1,s);
    }
    if(col-1>=0 && map[row][col-1]!='#' && visited[row][col-1]==false){
        check(row,col-1,s);
    }
    return;
}
void solve(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]=='$' || map[i][j]=='*'){
                check(i,j,map[i][j]);
                if(both){
                    good2+=count_all;
                }
                else{
                    good1+=count_all;
                }
                count_all=0;
                both=false;
            }
        }
    }
}

int main(){
    read_input();
    solve();
    cout << good2 << ' ' << good1;
    return 0;
}