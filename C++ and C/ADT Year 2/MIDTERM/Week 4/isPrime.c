#include<stdio.h>
#include<math.h>
int main(void){
    int n,i,prime=1;
    scanf("%d",&n);
    for(i=2;i<sqrt(n);i++){
        if (n%i==0) prime=0;
    }
    printf("%d",prime);
    return 0;
}
//Big O notation = O(sqrt(n))