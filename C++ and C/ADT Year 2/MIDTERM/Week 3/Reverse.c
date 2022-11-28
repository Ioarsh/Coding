#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    int i=0,whitespace=0,j,k=0;
    char temp[100000],**word=NULL;
    fgets(temp, sizeof(temp), stdin);
    while(temp[i]!='\0'){
        if(temp[i]==' '){
            whitespace+=1;
        }
        i++;
    }
    word=(char **)malloc(sizeof(char *) * (whitespace+1));
    for(i=0;i<whitespace+1;i++){
        word[i]=(char *)malloc(sizeof(char)*50);
        j=0;
        while(1){
            if(temp[k]==' '){
                k+=1;
                word[i][j]='\0';
                break;
            }
            else if((temp[k]<65 || temp[k]>90) && (temp[k]<97 || temp[k]>122)){
                word[i][j]=='\0';
                break;
            }
            word[i][j]=temp[k];
            k+=1;
            j+=1;
        }
    }
    for(i=whitespace;i>=0;i--){
        printf("%s ",word[i]);
    }
}