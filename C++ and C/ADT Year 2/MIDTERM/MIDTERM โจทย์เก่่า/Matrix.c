#include<stdio.h>
#include<stdlib.h>

typedef struct matrix{
    int **mat;
} matrix_t;

matrix_t *matrix=NULL;

matrix_t *buildmatrix(matrix_t *m,int n){
    int i,j;
    matrix=(matrix_t *)malloc(sizeof(matrix_t ));
    matrix->mat = (int **)malloc(sizeof(int *)*n);
    for(i=0;i<n;i++){
        matrix->mat[i] = (int *)malloc(sizeof(int )*n);
        for(j=0;j<n;j++){
            scanf("%d",&matrix->mat[i][j]);
        }
    }
    m=matrix;
    return m;
}

matrix_t *plus(matrix_t *a,matrix_t *b,int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            a->mat[i][j]=a->mat[i][j]+b->mat[i][j];
        }
    }
    free(b);
    return a;
}

void show(matrix_t *m,int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",m->mat[i][j]);
        }
    }
}

int main(void){
    int n;
    matrix_t *a =NULL,*b=NULL;
    scanf("%d",&n);
    a=buildmatrix(a,n);
    b=buildmatrix(b,n);
    a=plus(a,b,n);
    show(a,n);
    return 0;
}