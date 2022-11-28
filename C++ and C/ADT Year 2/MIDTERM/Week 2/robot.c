#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,x=0,y=1;
    double ans,location_x=0.00,location_y=0.00;
    char move;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf(" %c",&move);
        switch(move)
        {
            case 'F': location_x+=x; location_y+=y; printf("%.4f/",location_x); printf("%.4f\n",location_y); break;
            case 'R': 
            {
                if(x==0){
                    if(y==1){x=1;y=0;}
                    else{x=(-1);y=0;}
                }
                else{
                    if(x==1){x=0;y=(-1);}
                    else{x=0;y=1;}
                }
                printf("R\n");
                break;
            }
            case 'L':
            {
                if(x==0){
                    if(y==1){x=(-1);y=0;}
                    else{x=1;y=0;}
                }
                else{
                    if(x==1){x=0;y=1;}
                    else{x=0;y=(-1);}
                }
                printf("L\n"); 
                break; 
            }
            default: break;
        }
    }
    ans=sqrt((location_x*location_x)+(location_y*location_y));
    printf("%.4lf",ans);
    return 0;
}