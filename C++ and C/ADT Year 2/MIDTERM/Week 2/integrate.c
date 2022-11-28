#include<stdio.h>
#include<math.h>
#define PI (3.141592653589793)
double A,B;
#define f(x) A*sin((PI*x)/B)

int main()
{
    double answer,a,b,h,x,sum=0.00;
    int i,n;
    scanf("%lf %lf %lf %lf %d",&a,&b,&A,&B,&n);
    h=(b-a)/n;
    for(i=1;i<n;i++){
        x=a+i*h;
        sum=sum+f(x);
    }
    answer=(h/2)*(f(a)+f(b)+2*sum);
    printf("%.5lf",answer);
}