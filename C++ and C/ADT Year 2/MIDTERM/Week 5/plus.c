#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 10000

void convert(int *arr,char *temp){
    int i;
    for(i=0;i<strlen(temp)-1;i++){
        arr[strlen(temp)-2-i] = temp[i]-'0';
    }
    for(i=strlen(temp)-1;i<MAXSIZE;i++){
        arr[i] = -1;
    }
}

int main(void){
    char temp_x[MAXSIZE],temp_y[MAXSIZE];
    int x[MAXSIZE],y[MAXSIZE],sum[MAXSIZE],i,tod=0;
    for(i=0;i<MAXSIZE;i++){
        sum[i]= -1;
    }
    fgets(temp_x, sizeof(temp_x), stdin);
    fgets(temp_y, sizeof(temp_y), stdin);
    convert(x,temp_x);
    convert(y,temp_y);
    for(i=0;i<MAXSIZE;i++){
        if(x[i]==-1 && y[i]==-1 && tod==0) break;
        else if (x[i]==-1 && y[i]==-1 && tod!=0){
            sum[i]=tod;
            break;
        }
        else if(x[i]!=-1 && y[i]==-1){
            sum[i]=x[i]+tod;
            tod=0;
            if(sum[i]>=10){
                tod=(sum[i]/10);
                sum[i]%=10;
            }
        }
        else if(x[i]==-1 && y[i]!=-1){
            sum[i]=y[i]+tod;
            tod=0;
            if(sum[i]>=10){
                tod=(sum[i]/10);
                sum[i]%=10;
            }
        }
        else if(x[i]!=-1 && y[i]!=-1){
            sum[i]=x[i]+y[i]+tod;
            tod=0;
            if(sum[i]>=10){
                tod=(sum[i]/10);
                sum[i]%=10;
            }
        }
    }
    for(i=MAXSIZE-1;i>=0;i--){
        if(sum[i]!=-1)  printf("%d",sum[i]);
    }
}