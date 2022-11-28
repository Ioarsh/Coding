#include<iostream>
#include<cmath>
int main()
{
    int n,x,y,sum=0;
    float pos;
    std::cin >> n;
    for(int i=0;i<n;i++){
        std::cin >> x >> y;
        pos=sqrt(x*x + y*y);
        if(pos>=0 && pos<=2){sum+=5;}
        else if(pos>2 && pos<=4){sum+=4;}
        else if(pos>4 && pos<=6){sum+=3;}
        else if(pos>6 && pos<=8){sum+=2;}
        else if(pos>8 && pos<=10){sum+=1;}
        else{sum+=0;}
    }
    std::cout << sum << std::endl;
}