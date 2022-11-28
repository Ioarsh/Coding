#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    char          data;
    struct node *next;
} node_t;

typedef node_t stack_t;

stack_t *push(stack_t *s, char p){
    stack_t *node = (stack_t *)malloc(sizeof (stack_t));
    node->data = p;
    node->next = NULL;
    node->next = s;
    s = node;
    return s;
}

stack_t *pop(stack_t *s){
    stack_t *temp=NULL;
    if(s==NULL){
        return s;
    }
    temp=s;
    if(s->next==NULL){
        s=NULL;
    }
    else{
        s=temp->next;
    }
    free(temp);
    return s;
}

void empty(stack_t *s){
    if(s==NULL){
        printf("1\n");
    }
    else{
        printf("0\n");
    }
}

/*void show(stack_t *a){
    while(a!=NULL){
        if(a->next==NULL) printf("%c",a->data);
        else printf("%c ",a->data);
        a = a->next;
    }
    if(a==NULL) printf("\n");
}*/

int main(void){
    stack_t *s =NULL;
    int n,i,krob;
    char p;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf(" %c",&p);
        krob=0;
        switch(p){
            case ')':
                if(s!=NULL){
                    if(s->data=='('){
                    s = pop(s);
                    krob=1;
                    }
                }
                break;
            case '}':
                if(s!=NULL){
                    if(s->data=='{'){
                    s = pop(s);
                    krob=1;
                    }
                }
                break;
            case ']':
                if(s!=NULL){
                    if(s->data=='['){
                    s = pop(s);
                    krob=1;
                    }
                }
                break;
            default: break;
        }
        if(krob==1) continue;
        s = push(s,p);
    }
    empty(s);
}