#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int        data;
    struct node *next;
    struct node *previous;
} node_t;

typedef struct queue{
    node_t *front;
    node_t *rear;

} queue_t;

queue_t *enqueue(queue_t *q, int value){
    node_t *node = (node_t *)malloc(sizeof (node_t));
    node->data=value;
    node->next=NULL;
    node->previous=NULL;
    if(q==NULL){
        queue_t *temp = (queue_t *)malloc(sizeof(queue_t));
        temp->front=NULL;
        temp->rear=NULL;
        node->next = temp->rear;
        temp->rear = node;
        temp->front = node;
        return temp;
    }
    else{
        node->next = q->rear;
        if(q->rear!=NULL){
            q->rear->previous=node;
        }
        q->rear = node;
        if(q->front==NULL){
            q->front=node;
        }
        return q;
    }
}

queue_t *dequeue(queue_t *q){
    node_t *temp = NULL;
    int     value = 0;
    if(q==NULL){
        printf("Queue is empty.\n");
        return q;
    }
    if(q->front == NULL){
        printf("Queue is empty.\n");
        return q;
    }
    temp = q->front;
    value = q->front->data;
    if(q->front == q->rear){
        q->front = NULL;
        q->rear = NULL;
    }
    else{
        q->front = q->rear;
        while(q->front->next!=temp){
            q->front = q->front->next;
        }
        q->front->next = NULL;
    }
    printf("%d\n",value);
    free(temp);
    return q;
}

void show(queue_t *q){
    if(q==NULL)            printf("Queue is empty.\n");
    else if(q->rear==NULL) printf("Queue is empty.\n");
    else{
        node_t *temp=q->front;

        while(temp!=NULL){
            if(temp->previous==NULL) printf("%d\n",temp->data);
            else printf("%d ",temp->data);
            temp=temp->previous;
        }
    }
    

}

void empty(queue_t *q){
    if(q==NULL)            printf("Queue is empty.\n");
    else if(q->rear==NULL) printf("Queue is empty.\n");
    else                   printf("Queue is not empty.\n");

}

void size(queue_t *q){
    int count=0;
    if(q!=NULL){
        node_t *temp=q->rear;
        while(temp!=NULL){
            temp=temp->next;
            count+=1;
        }
        printf("%d\n",count);

    }
    else{
        printf("0\n");
    }

}

int main(void){
    queue_t *q =NULL;
    int      n, i, command, value;

    scanf("%d", &n);
    for (i=0; i<n; i++){
        scanf("%d", &command);
        switch(command){
            case 1:
                scanf("%d", &value);
                q = enqueue(q, value);
                break;
            case 2:
                q = dequeue(q);
                break;
            case 3:
                show(q);
                break;
            case 4:
                empty(q);
                break;
            case 5:
                size(q);
                break;
        }
    }
    return 0;
}