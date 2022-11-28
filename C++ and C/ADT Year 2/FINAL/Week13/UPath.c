#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int data;
    struct stack *next;
} stack_t;

typedef int** graph_t;

void push(stack_t **s, int value){
    stack_t *node = (stack_t *)malloc(sizeof(stack_t));
    node->data = value;
    node->next = *s;
    *s = node;
}

int pop(stack_t **s) {
    if (*s == NULL){
        return -1;
    } else {
        stack_t *temp;
        temp = *s;
        *s = (*s)->next;
        return temp->data;
    } 
}

int is_in_stack(stack_t **s, int value) {
    stack_t *temp = *s;
    while (temp != NULL) {
        if (temp->data == value) {
            return 1;
        } else {
            temp = temp->next;
        }
    }
    return 0;
}

void print_stack(stack_t **s) {
    stack_t *temp = *s;
    stack_t *bucket = NULL;

    while (temp != NULL) {
        push(&bucket, temp->data);
        temp = temp->next;
    }
    while (bucket != NULL) {
        printf("%d", bucket->data);
        pop(&bucket);
    }
}

stack_t *visited = NULL;

graph_t init_graph(int n) {
    int i, j;
    int *row;
    int **graph = (int **)malloc(sizeof(int *) * n);
    for (i=0; i<n; i++) {
        row = (int *)malloc(sizeof(row) * n);
        for (j=0; j<n; j++) {
            row[j] = 0;
        }
        graph[i] = row;
    }
    return graph;
}

void get_edges(graph_t graph, int vertex, int size, stack_t **edges) {
    int i;
    for (i=0; i<vertex; i++) {
        if (is_in_stack(edges, i) != 1 && graph[vertex][i] != 0 && is_in_stack(&visited, i) != 1) {
            push(edges, i);
        }
    }
    for (i=vertex; i<size; i++) {
        if (is_in_stack(edges, i) != 1 && graph[i][vertex] != 0 && is_in_stack(&visited, i) != 1) {
            push(edges, i);
        }
    }
   
}



int get_path_len(graph_t graph) {
    int i;
    int len = 0;
    stack_t *temp = visited;
    while (temp->next != NULL) {
        len += graph[temp->data][temp->next->data];
        temp = temp->next;
    }
    // printf("len %d\n", len);
    return len;
}

void get_path(graph_t graph, int begin, int finish, int size, int *min) {
    int p, l;
    stack_t *edges = NULL;
    push(&visited, begin);
    // printf("path :");
    // print_stack(&path);
    // printf("**\n");
    get_edges(graph, begin, size, &edges);
    while (edges != NULL) {
        // print_stack(&edges);
        p = pop(&edges);
        if (p == finish) {
            push(&visited, finish);
            // printf("reached %d\n success path : ", finish);
            // print_stack(&path);
            // printf("\n");
            l = get_path_len(graph);
            if (l < *min || *min == -1) {
                *min = l;
            }
            pop(&visited);
            // return;
            // p = pop(&edges);
        } else {
            // printf("\nchoose path : %d\n", p);
            get_path(graph, p, finish, size, min);
        }
    }
    pop(&visited);
}

int get_min_path(graph_t graph, int begin, int finish, int size) {
    int min = -1;
    get_path(graph, begin, finish, size, &min);
    return min;
}

void print_graph(graph_t graph, int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int n, m, p, i;
    int u, v, w;
    int s, t;
    int min_len;
    graph_t graph = NULL;
    scanf("%d %d %d", &n, &m, &p);
    graph = init_graph(n);
    for (i=0; i<m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }
    // print_graph(graph, n);

    for (i=0; i<p; i++) {
        scanf("%d %d", &s, &t);
        min_len = get_min_path(graph, s, t, n);
        printf("%d\n", min_len);
    }
    return 0;
}