#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int data;
    struct node *next;
} node_t;

node_t *append(node_t *a){
    int n;
    node_t *h = (node_t *)malloc(sizeof (node_t));
    node_t *l=a;
    scanf("%d",&n);
    h->data=n;
    h->next=NULL;
    if(a==NULL){
        a=h;
        return a;
    }
    else{
        while (l->next != NULL) {l=l->next;}
        l->next=h;
        return a;
    }
}

node_t *reverse(node_t *a){
    node_t *prev = NULL;
    node_t *current = a;
    node_t *next =NULL;
    while(current!=NULL){
        next =current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    a=prev;
    return a;
}

void show(node_t *a){
    while(a!=NULL){
        if(a->next==NULL) printf("%d",a->data);
        else printf("%d ",a->data);
        a = a->next;
    }
    if(a==NULL) printf("\n");
}

void get(node_t *a){
    int count=0,n;
    scanf("%d",&n);
    while(a!=NULL){
        if(count==n) {
            printf("%d\n",a->data); 
            break;
        }
        count+=1;
        a = a->next;
    }
}

node_t *cut(node_t *a){
    int s,e,count=0;
    node_t *temp=a;
    scanf("%d %d",&s,&e);
    while(a!=NULL){
        if(count==s){
            temp=a;
        }
        if(count==e){
            a->next=NULL;
            break;
        }
        count+=1;
        a = a->next;
    }
    a=temp;
    return a;
}


int main(void){
    node_t *startNode;
    int n,i;
    char command;

    startNode = NULL;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf(" %c",&command);
        switch(command){
            case 'A':
                startNode = append(startNode);
                break;
            case 'G':
                get(startNode);
                break;
            case 'S':
                show(startNode);
                break;
            case 'R':
                startNode = reverse(startNode);
                break;
            case 'C':
                startNode = cut(startNode);
                break;
            default:
                break;
        }
    }
    return 0;
}