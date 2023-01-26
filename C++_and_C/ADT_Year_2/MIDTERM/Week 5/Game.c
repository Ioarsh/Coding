#include<stdio.h>
#include<stdlib.h>

typedef struct player{
    int limit;
    int drink;
    int player_no;
    struct player *next;
} player_t;

player_t *append(player_t *a,int limit,int no){
    player_t *h = (player_t *)malloc(sizeof (player_t));
    player_t *l=a;
    h->limit=limit;
    h->drink=0;
    h->player_no=no+1;
    h->next=NULL;
    if(a==NULL){
        return h;
    }
    else{
        while (l->next != NULL) {l=l->next;}
        l->next=h;
        return a;
    }
}

player_t *setup(player_t *a,int n){
    player_t *temp=a;
    while(a!=NULL){
        if(a->player_no==n) {
            a->next=temp;
            temp=a;
            break;
        }
        a = a->next;
    }
    return temp;

}


int checkdigit(int num, int digit){
    int r;
    if(num%digit==0) return 1;
    while(num!=0){
        r=num%10;
        if(r==digit){
            return 1;
        }
        num/=10;
    }
    return 0;
}

player_t *game(player_t *a, int k){
    player_t *temp=NULL;
    int count=1,h;
    while(a->next!=a){
        h=0;
        if(checkdigit(count,k)==1){
            a->next->drink+=1;}
        if(a->next->drink > a->next->limit){
                h=1;
                temp=a->next;
                a->next=a->next->next;
                free(temp);
                temp=NULL;
                }
        if(h==0){
            a = a->next;
        }
        count+=1;
    }
    return a;
}

int main(void){
    int n,k,i,limit;
    player_t *startPlayer;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&limit);
        startPlayer = append(startPlayer,limit,i);
    }
    startPlayer = setup(startPlayer,n);
    startPlayer = game(startPlayer,k);
    printf("%d",startPlayer->player_no);
}