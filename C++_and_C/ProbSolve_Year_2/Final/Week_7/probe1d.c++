#include "probelib.h"
#include <cstdio>

int n;

main()
{
    int n = probe_init();
    int l=0,r=n-1,m;
    while(l<r){
        m=l + (r-l)/2;
        if(probe_check(l,m)){
            r=m;
        }
        else{
            l=m+1;
        }
    }
    probe_answer(l);
}