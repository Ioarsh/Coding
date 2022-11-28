#include<stdio.h>
#include<stdlib.h>


int *insertion_sort(int* list,int n){
    int i,j,temp;
    for(i=1;i<n;i++){
            for(j=i;j-1>=0;j--){
                if(list[j]>list[j-1])
                    break;
                temp=list[j];
                list[j]=list[j-1];
                list[j-1]=temp;
            }
            for(j=0;j<n;j++){
                printf("%d ",list[j]);
            }
            printf("\n");
    }
    return list;
}

int main(){
    int n,i;
    scanf("%d",&n);
    int *list=(int* )malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        scanf("%d",&list[i]);
    }
    list=insertion_sort(list,n);
    return 0;
}