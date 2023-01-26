#include<stdio.h>
int main()
{
    int weight,height;
    double bmi,height_m;
    scanf("%d %d",&weight,&height);
    height_m=(double)height/100;
    bmi=weight/(height_m*height_m);
    if(bmi>=18.6)
        {
            if(bmi>=25)
            {
                if(bmi>=30)
                {
                    printf("BMI: %.4lf and you are obese",bmi);
                }
                else
                {
                    printf("BMI: %.4lf and you are overweight",bmi);
                }
            }
            else
            {
                printf("BMI: %.4lf and you are healthy",bmi);
            }
        }
    else
    {
        printf("BMI: %.4lf and you are underweight",bmi);
    }
    return(0);
}