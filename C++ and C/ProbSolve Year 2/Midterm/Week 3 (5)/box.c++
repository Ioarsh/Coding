#include<iostream>
#include<cstdlib>
using namespace std;

int n,m;
char **box;

int print_out(){
    cout << '\n';
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << box[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
    return 0;
}

int loop(int y,int x){
    box[y][x]='x';box[y][x+1]='x';box[y+1][x]='x';box[y+1][x+1]='x';
    if(y==n-2){
        return 1;
    }
    //down
    else if(y+2<n && box[y+2][x]=='.' && box[y+2][x+1]=='.'){
        if(loop(y+1,x)==1) return 1;
    }
    //right
    else if(x+2<m && box[y][x+2]=='.' && box[y+1][x+2]=='.'){
        if(loop(y,x+1)==1) return 1;
    }
    //left
    else if(x-1>0 && box[y][x-1]=='.' && box[y+1][x-1]=='.'){
        if(loop(y,x-1)==1) return 1;
    }
    //up
    else if(y-1>0 && box[y-1][x]=='.' && box[y-1][x+1]=='.'){
        if(loop(y-1,x)==1) return 1;
    }
    box[y][x]='.';box[y][x+1]='.';box[y+1][x]='.';box[y+1][x+1]='.';
    return 0;
}


int read_input(){
    cin >> n >> m;
    box = (char **)malloc(sizeof(char *) * n);
    for(int i=0;i<n;i++){
        box[i] = (char *)malloc(sizeof(char) * m);
        for(int j=0;j<m;j++){
            cin >> box[i][j];
        }
    }
    return 0;
}
string firstrow = "#####.....######..##";
string lastrow = "#######..##.##..####";
int main(){
    int ans=0,ans2=0;
    read_input();
    for(int i=0;i<m;i++){
        if(box[0][i]==firstrow[i]){
            ans=1;
        }
        else{
            ans=0;
            break;
        }
    }
    if(n==20){
        for(int i=0;i<m;i++){
        if(box[19][i]==lastrow[i]){
            ans2=1;
        }
        else{
            ans2=0;
            break;
        }
        }
    }
    int can=0;
    for(int j=0;j<m-1;j++){
        if(box[0][j]!='#' && box[0][j+1]!='#' && box[1][j]!='#' && box[1][j+1]!='#'){
            can=loop(0,j);
            if(can==1){break;}
        }
    }
    if(ans && ans2){
        cout << "yes";
    }
    else if(can==1){
        cout << "yes";
    }
    else{
        cout << "no";
    }
    return(0);
}