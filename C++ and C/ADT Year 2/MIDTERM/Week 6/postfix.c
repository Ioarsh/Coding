#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    float          data;
    struct node *next;
} node_t;

typedef node_t stack_t;

stack_t *push(stack_t *s, float value){
    stack_t *node = (stack_t *)malloc(sizeof (stack_t));
    node->data = value;
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
    s=temp->next;
    free(temp);
    return s;
}


void plus(stack_t **s, float top, float bottom){
    stack_t *temp = *s;
    temp->next->data=bottom+top;
}

void minus(stack_t **s, float top, float bottom){
    stack_t *temp = *s;
    temp->next->data=bottom-top;
}

void multiply(stack_t **s, float top, float bottom){
    stack_t *temp = *s;
    temp->next->data=bottom*top;
}

void divide(stack_t **s, float top, float bottom){
    stack_t *temp = *s;
    temp->next->data=bottom/top;
}

int main(void){
    stack_t *s=NULL;
    int n,i,x;
    char in;
    scanf("%d",&n);
    for(i=0;i<n;i++){
         scanf(" %c",&in);
         if(in=='+' || in=='-' || in=='*' || in=='/'){
            switch (in){
                case '+':{
                    plus(&s,s->data,s->next->data);
                    s=pop(s);
                    break;
                }
                case '-':{
                    minus(&s,s->data,s->next->data);
                    s=pop(s);
                    break;
                }
                case '*':{
                    multiply(&s,s->data,s->next->data);
                    s=pop(s);
                    break;
                }
                case '/':{
                    divide(&s,s->data,s->next->data);
                    s=pop(s);
                    break;
                }
                default: break;
            }
         }
         else{
            x = in - '0';
            s=push(s,x);
         }
    }
    printf("%.2f",s->data);
}