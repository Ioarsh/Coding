#include<stdio.h>
#include<stdlib.h>
#define MAX_POSSIBLE 999999

typedef struct node{
    int name;
    int weight;
    struct node* next;
} node_t;

typedef struct AdjList {
    node_t* head;
} adjList_t;

typedef struct Graph {
    int V;
    adjList_t* array;
} graph_t;

node_t* create_node(int name,int weight)
{
    node_t* node= (node_t*)malloc(sizeof(node_t));
    node->name= name;
    node->weight=weight;
    node->next = NULL;
    return node;
}

graph_t* create_graph(int V)
{
    int i;
    graph_t* graph = (graph_t*)malloc(sizeof(graph_t));
    graph->V = V;
    graph->array=(adjList_t*)malloc(sizeof(adjList_t)*V);
    for(i=0;i<V;i++){
        graph->array[i].head = NULL;
    }
    return graph;
}

void addEdge(graph_t* graph, int name1, int name2, int weight){
    node_t* temp = NULL;
    node_t* newNode = create_node(name2,weight);
 
    if (graph->array[name1].head == NULL) 
        graph->array[name1].head = newNode;
    
    else {
        temp = graph->array[name1].head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    newNode = create_node(name1,weight);
    if (graph->array[name2].head == NULL)
        graph->array[name2].head = newNode;
    else {
        temp = graph->array[name2].head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


typedef struct stack{
    int data;
    struct stack *next;
} stack_t;

stack_t *push(stack_t *s, int value){
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

int top(stack_t *s){
    return(s->data);
}

int check(stack_t *s, int value){
    while (s != NULL){
        if (s->data == value){
            return 1;
        }
        s = s->next;
    }
    return 0;
}

stack_t *visited=NULL;
stack_t *weight=NULL;
stack_t *total=NULL;
int Short(graph_t *graph,int start,int end){
    if (start==end){
        int sum=0;
        stack_t *temp=weight;
        while (temp != NULL)
        {
            sum+= temp->data;
            temp=temp->next;
        }
        total = push(total,sum);
        weight = pop(weight);
        return 0;
    }
    node_t* current = graph->array[start].head;
    visited = push(visited,start);
    while(current!=NULL){
        if(check(visited,current->name)==0){
            weight=push(weight,current->weight);
            if(Short(graph,current->name,end)){
                return 0;
            }
        }
        current=current->next;
    }
    visited = pop(visited);
    weight = pop(weight);
    return 0;
}
int main(void){
    int n,m,p,u,v,w,s,t,i;
    scanf("%d %d %d",&n,&m,&p);
    graph_t* graph = create_graph(n);
    for(i=0;i<m;i++){
        scanf("%d %d %d",&u,&v,&w);
        addEdge(graph,u,v,w);
    }
    for(i=0;i<p;i++){
        scanf("%d %d",&s,&t);
        Short(graph,s,t);
        int min=MAX_POSSIBLE;
        while(total!=NULL){
            if(top(total)<min)
                min=top(total);
            total=pop(total);
        }
        if(min==MAX_POSSIBLE)
            printf("%d\n",-1);
        else
            printf("%d\n",min);
    }
    return 0;
}