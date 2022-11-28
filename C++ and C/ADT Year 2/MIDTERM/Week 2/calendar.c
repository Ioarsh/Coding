#include<stdio.h>
int findStart(int m,int y)
{
    int c,h,b;
    c=y/100;
    if(m==1){m=13;y=y-1;}
    else if(m==2){m=14;y=y-1;}
    b=y%100;
    h=1+(13*(m+1)/5)+b+b/4+c/4+5*c;
    h=h%7;
    return(h);
}

int main()
{
    int day,year,month,n,i,count=0,j,bug=0;
    printf("Enter year: ");
    scanf("%d",&year);
    /*printf("Enter month: ");
    scanf("%d",&month);*/
    printf("====================\n");
    for(j=1;j<=12;j++)
    {
        month=j;
        switch(month)
        {
        case 1: printf("January %d\n",year); n=31; break;
        case 2:{ 
            printf("Febuary %d\n",year); 
            n=28;
            if(year%4==0 && year%100!=0){n=29;}
            else if(year%400==0) {n=29;}
            break;
        }
        case 3: printf("March %d\n",year); n=31; break;
        case 4: printf("April %d\n",year); n=30; break;
        case 5: printf("May %d\n",year); n=31; break;
        case 6: printf("June %d\n",year); n=30; break;
        case 7: printf("July %d\n",year); n=31; break;
        case 8: printf("August %d\n",year); n=31; break;
        case 9: printf("September %d\n",year); n=30; break;
        case 10: printf("October %d\n",year); n=31; break;
        case 11: printf("November %d\n",year); n=30; break;
        case 12: printf("December %d\n",year); n=31; break;
        default: break;
        }
        day=findStart(month,year);
        printf("Sun Mon Tue Wed Thu Fri Sat\n");
        day=findStart(month,year);
        switch(day)
        {
            case 0: printf("                        "); count=6; break;
            case 1: count=0; break;
            case 2: printf("    "); count=1; break;
            case 3: printf("        "); count=2; break;
            case 4: printf("            "); count=3; break;
            case 5: printf("                "); count=4; break;
            case 6: printf("                    "); count=5; break;
            default: break;
        }
        for(i=1;i<=n;i++)
        {
            if(count>6)
            {
                count=0;
                printf("\n");
            }
            if(i<10){printf("  %d ",i);}
            else{printf(" %d ",i);}
            count+=1;
            }
            printf("\n");
            printf("====================\n");
    }
    /*switch(month)
    {
        case 1: printf("January %d\n",year); n=31; break;
        case 2:{ 
            printf("Febuary %d\n",year); 
            n=28;
            if(year%4==0 && year%100!=0){n=29;}
            else if(year%400==0) {n=29;}
            break;
        }
        case 3: printf("March %d\n",year); n=31; break;
        case 4: printf("April %d\n",year); n=30; break;
        case 5: printf("May %d\n",year); n=31; break;
        case 6: printf("June %d\n",year); n=30; break;
        case 7: printf("July %d\n",year); n=31; break;
        case 8: printf("August %d\n",year); n=31; break;
        case 9: printf("September %d\n",year); n=30; break;
        case 10: printf("October %d\n",year); n=31; break;
        case 11: printf("November %d\n",year); n=30; break;
        case 12: printf("December %d\n",year); n=31; break;
        default: break;
    }
    day=findStart(month,year);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");
    day=findStart(month,year);
    switch(day)
        {
            case 0: printf("                        "); count=6; break;
            case 1: count=0; break;
            case 2: printf("    "); count=1; break;
            case 3: printf("        "); count=2; break;
            case 4: printf("            "); count=3; break;
            case 5: printf("                "); count=4; break;
            case 6: printf("                    "); count=5; break;
            default: break;
        }
    for(i=1;i<=n;i++)
    {
        if(count>6)
        {
            count=0;
            printf("\n");
        }
        if(i<10){printf("  %d ",i);}
        else{printf(" %d ",i);}
        count+=1;
    }
    printf("\n");*/
    return 0;
}