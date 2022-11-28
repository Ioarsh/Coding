#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TEXTSIZE 50

char *insertion_sort(char* text,int n){
    int i,j;
    char temp;
    char *temptext=(char *)malloc(sizeof(char)*strlen(text));
    strcpy(temptext,text);
    for(i=1;i<n;i++){
            for(j=i;j-1>=0;j--){
                if(temptext[j]>temptext[j-1])
                    break;
                temp=temptext[j];
                temptext[j]=temptext[j-1];
                temptext[j-1]=temp;
            }
    }
    return temptext;
}

void anagram(char** table,char *text,int m){
    int i;
    for(i=0;i<m;i++){
        if(strlen(text)==strlen(table[i])){
            char *temp=(char *)malloc(sizeof(char)*strlen(text));
            temp=insertion_sort(table[i],strlen(text));
            text=insertion_sort(text,strlen(text));
            if(strcmp(temp,text)==0)
                printf("%s ",table[i]);
            free(temp);
        }
    }
    printf("\n");
}

int main(void){
    int m,n,i;
    char* text=NULL;
    text = (char *)malloc(sizeof(char)*TEXTSIZE);

    scanf("%d %d",&m,&n);
    char **table=(char**)malloc(sizeof(char*)*m);
    for(i=0;i<m;i++){
        scanf("%s",text);
        table[i]=(char*)malloc(sizeof(char)*strlen(text));
        strcpy(table[i],text);
    }
    for(i=0;i<n;i++){
        scanf("%s",text);
        anagram(table,text,m);
    }
    return 0;
}