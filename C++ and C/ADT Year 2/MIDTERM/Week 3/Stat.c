#include <stdio.h>
#include <stdlib.h>

void findStats(int n, int *nums, int *maxi, int *mini, double *avg){
    int i;
    *maxi=*nums;
    *mini=*nums;
    for(i=0;i<n;i++){
        if(*(nums+i)>*maxi){*maxi=*(nums+i);}
        else if(*(nums+i)<*mini){*mini=*(nums+i);}
        *avg+=*(nums+i);
    }
    *avg=*avg/n;
}

int main(void) {
    int n,i,maxi,mini;
    double avg;
    int *nums;

    scanf("%d", &n);
    nums = (int *)malloc(sizeof (int) * n);
    for(i=0;i<n;i++){
        scanf("%d", nums+i);
    }
    findStats(n,nums,&maxi,&mini,&avg);
    printf("%.2f %d %d", avg, maxi, mini);
    return 0;
}