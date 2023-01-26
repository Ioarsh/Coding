#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    int m,p,n,i=0,count,j,k;
    char *mainstring=NULL , *substring=NULL;
    scanf("%d %d %d",&m,&p,&n);

    substring=(char *)malloc(sizeof(char) * p);
    scanf("%s",mainstring);
    scanf("%s",substring);
    while(i<m){
        count=0;
        if(i+p>m){
            printf("%c",mainstring[i]);
            i+=1;
            continue;
        }
        for(j=0;j<p;j++){
            if(mainstring[i+j]!=substring[j]){
                count+=1;
            }
        }
        if(count<=n && count!=0){
            printf("[");
            for(k=0;k<p;k++){
                if(mainstring[i+k]==substring[k]){
                    printf("%c",mainstring[i+k]);
                }
                else printf("?");
            }
            printf("]");
            i+=p;
        }
        else if(count==0){
            printf("[");
            printf("%s",substring);
            printf("]");
            i+=p;

        }
        else{
            printf("%c",mainstring[i]);
            i+=1;
        }
    }
}