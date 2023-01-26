#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    char          data;
    struct node *next;
} node_t;

typedef node_t stack_t;

stack_t *push(stack_t *s, char value){
    stack_t *node = (stack_t *)malloc(sizeof (stack_t));
    node->data = value;
    node->next = NULL;
    node->next = s;
    s = node;
    return s;
}

stack_t *reverse(stack_t *a){
    stack_t *prev = NULL;
    stack_t *current = a;
    stack_t *next =NULL;
    while(current!=NULL){
        next =current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    a=prev;
    return a;
}

int Check(stack_t **x,stack_t **y){
    stack_t *temp_x=NULL,*temp_y=NULL;
    int count_x=0,count_y=0;
    temp_x=*x;
    temp_y=*y;
    if(temp_x==NULL||temp_y==NULL){
        return 0;
    }
    while(temp_x!=NULL){
        count_x+=1;
        temp_x=temp_x->next;
    }
    while(temp_y!=NULL){
        count_y+=1;
        temp_y=temp_y->next;
    }
    if(count_x==count_y){
        temp_x=*x;
        temp_y=*y;
        while(1){
        if(temp_x==NULL) break;
        if(temp_x->data!=temp_y->data){
            return 0;
        }
        temp_x=temp_x->next;
        temp_y=temp_y->next;
        }
        return 1;
    }
    else return 0;
}

int main(void){
    stack_t *x=NULL,*y=NULL;
    char in;
    while(1){
        scanf(" %c",&in);
        if(in=='x') break;
        x=push(x,in);
    }
    while(1){
        scanf(" %c",&in);
        if(in=='y') break;
        y=push(y,in);
    }
    x=reverse(x);
    printf("%d",Check(&x,&y));
}