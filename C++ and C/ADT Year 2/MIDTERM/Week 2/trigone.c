#include<stdio.h>
#include<math.h>
#define PI (3.141592653589793)

double fac(int x){
    int i;
    double sum=1.00;
    for(i=1;i<=x;i++){
        sum=sum*i;
    }
    return sum;
}

double Fsin(double x){
    double sum=0.00;
    int i;
    for(i=0;i<10;i++){
        sum=sum+(pow(-1,i))*(pow(x,2*i+1)/(fac(2*i+1)));
    }
    return sum;
}

int main()
{
    int x;
    double x_radian,s,c,t;
    scanf("%d",&x);
    x_radian=PI*x/180;
    s=Fsin(x_radian);
    c=sqrt(1-pow(s,2));
    t=s/c;
    printf("%.14lf %.14lf %.14lf",s,c,t);
}

