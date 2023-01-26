#include<stdio.h>
#include<stdlib.h>

typedef struct player{
    int limit;
    int no;
    struct player *next;
} player_t;

player_t *append(player_t *a, int limit, int no){
    player_t *temp = (player_t *)malloc(sizeof (player_t));
    temp->limit=limit;
    temp->no=no;
    temp->next = NULL;
    if(a==NULL) return temp;
    else{
        a->next = temp;
        return temp;
    }
}

int check(int j,int k){
    int r;
    if(j%k==0) return 1;
    for(j=j; j!=0; j/=10){
        r=j%10;
        if(r==k) return 1;

    }
    return 0;
}

player_t *game(player_t *a, int k){
    player_t *temp=NULL;
    int count=1,h;
    while(a->next!=a){
        h=0;
        if(check(count,k)==1){
            a->next->limit-=1;
        }
        if(a->next->limit<0){
            h=1;
            temp=a->next;
            a->next=a->next->next;
            free(temp);
            temp=NULL;
        }
        if(h==0){
            a=a->next;
        }
        count+=1;
    }
    return a;
}


int main(){
    player_t *now=NULL;
    player_t *back=NULL;
    int n,k,limit,i;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&limit);
        now = append(now,limit,i+1);
        if(i==0) back=now;
    }
    now->next=back;
    now = game(now,k);
    printf("%d\n",now->no);
}