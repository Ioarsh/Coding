#include<stdio.h>
#include<math.h>
int Calculate(int m,int n){
    int i,times,temp;
    if(m==0 || n==0) return 0;
    if(m==1) return n;
    if(n==1) return m;
    if(n>=m) temp=m;
    else temp=n;
    for(i=0;pow(2,i)<=temp;i++){
        times=pow(2,i);
    }
    if(m==n && m-times==0) return 1;
    if(times<(n-times))  return 1+Calculate(m-times,n)+Calculate(times,n-times);
    else return 1+Calculate(m-times,n)+Calculate(n-times,times);
}
int main(void){
    int m,n;
    scanf("%d %d",&m,&n);
    printf("%d",Calculate(m,n));
    return 0;
}
//O(min(m,n))