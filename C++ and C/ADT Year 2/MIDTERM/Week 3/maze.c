#include<stdio.h>
#include<stdlib.h>

int traverseMaze(int n, char **m, int x, int y);

int main(void){
    int i,j,s_i,s_j,n;
    char **maze,temp;
    scanf("%d",&n);

    maze = (char **)malloc(sizeof(char *) * n);
    for(i=0;i<n;i++){
        maze[i] = (char *)malloc(sizeof(char) * n);
        for(j=-1;j<n;j++){
            maze[i][j]=getchar();
            if(maze[i][j]=='S'){
                s_i=i;
                s_j=j;
            }
        }
    }
    traverseMaze(n,maze,s_i,s_j);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%c",maze[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int traverseMaze(int n, char **m, int x, int y){
    if(m[x][y]!='S' && m[x][y]!='#') m[x][y]='.';

    if((m[x][y+1]=='G' || m[x][y-1]=='G' || m[x+1][y]=='G' || m[x-1][y]=='G')){
        return 1;
    }
    if(y+1<n && m[x][y+1]==' '){
        if(traverseMaze(n,m,x,y+1)==1) return 1;
    }
    if(x+1<n && m[x+1][y]==' '){
        if(traverseMaze(n,m,x+1,y)==1) return 1;
    }
    if(x-1>=0 && m[x-1][y]==' '){
        if(traverseMaze(n,m,x-1,y)==1) return 1;
    }
    if(y-1>=0 && m[x][y-1]==' '){
        if(traverseMaze(n,m,x,y-1)==1) return 1;
    }
    m[x][y]=' ';
    return 0;
}