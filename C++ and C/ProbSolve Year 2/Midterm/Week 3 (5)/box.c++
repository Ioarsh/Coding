#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    char **box;
    box = (char **)malloc(sizeof(char *) * n);
    for(int i=0;i<n;i++){
        box[i] = (char *)malloc(sizeof(char) * m);
        for(int j=0;j<m;j++){
            cin >> box[i][j];
        }
    }
    return 0;
}