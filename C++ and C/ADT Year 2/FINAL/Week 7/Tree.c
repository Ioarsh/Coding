#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* parent;
    struct node* first_child;
    struct node* next_sibling;
} node_t;
typedef node_t tree_t;

typedef struct stacknode {
    int          data;
    struct stacknode *next;
} stacknode_t;
typedef stacknode_t stack_t;

typedef struct queuenode{
    int        data;
    struct queuenode *next;
    struct queuenode *previous;
} queuenode_t;
typedef struct queue{
    queuenode_t *front;
    queuenode_t *rear;

} queue_t;

/// Stack implementation
stack_t *s=NULL;
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

void clearstack(){
  while(s!=NULL){
    s=pop(s);
  }
}

/// queue implementation
queue_t *q=NULL;
queue_t *enqueue(queue_t *q, int value){
    queuenode_t *node = (queuenode_t *)malloc(sizeof (queuenode_t));
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
    queuenode_t *temp = NULL;
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
    printf("%d ",value);
    free(temp);
    return q;
}


/// case 3: search
tree_t *search_node(tree_t *t, int node_value){
    tree_t *pos=NULL;
    if (t==NULL || t->value==node_value)
        return t;
    pos = search_node(t->first_child, node_value);
    if (pos!=NULL)
        return pos;
    else
        return search_node(t->next_sibling,node_value);
}

tree_t *search_previous_node(tree_t *t, tree_t *pos){
    if (t==NULL || t->first_child==pos || t->next_sibling==pos){
      return t;
    }
    tree_t *temp = search_previous_node(t->first_child, pos);
    if (temp!=NULL)
      return temp;
    return search_previous_node(t->next_sibling, pos);
}

int search(tree_t *t, int node_value){
    node_t *have=NULL;
    have=search_node(t,node_value);
    return have!=NULL;
}

/// case 1: attach
tree_t *attach(tree_t *t, int parent_value, int child_value){
    node_t *node = (node_t*)malloc(sizeof(node_t)), *pos=NULL;
    node->value=child_value;
    node->parent=NULL;
    node->first_child=NULL;
    node->next_sibling=NULL;
    if(t==NULL){
        t=node;
        return t;
    }
    pos = search_node(t,parent_value);
    node->parent=pos;
    if(pos->first_child==NULL)
        pos->first_child=node;
    else{
        pos = pos->first_child;
        while(pos->next_sibling!= NULL){
            pos = pos->next_sibling;
        }
        pos->next_sibling=node;
    }
    return t;
}

/// case 2: detach
void delete(tree_t *t){
  if(t==NULL)
    return;
  delete(t->first_child);
  delete(t->next_sibling);
  free(t);
}

tree_t *detach(tree_t *t, int node_value){
  tree_t *pos=NULL, *pre=NULL;
  pos=search_node(t,node_value);
  if(t==pos){
    t=NULL;
    free(pos);
    return t;
  }
  if(pos==NULL){
    return t;
  }
  else{
    pre=search_previous_node(t,pos);
    if(pre->first_child==pos){
      pre->first_child=pos->next_sibling;
    }
    else if(pre->next_sibling==pos){
      pre->next_sibling=pos->next_sibling;
    }
    delete(pos->first_child);
    free(pos);
    return t;
  }
}
 
/// case 4: degree
int degree(tree_t *t, int node_value){
  int count=0;
  tree_t *pos=search_node(t,node_value);;
  if(pos->first_child!=NULL){
    count+=1;
    pos=pos->first_child;
    pos=pos->next_sibling;
    while(pos!=NULL){
      count+=1;
      pos=pos->next_sibling;
    }
  }
  return count;
}

/// case 5: is_root
int is_root(tree_t *t, int node_value){
    return t->value==node_value;
}

/// case 6: is_leaf
int is_leaf(tree_t *t, int node_value){
    node_t *that_node=NULL;
    that_node=search_node(t,node_value);
    return that_node->first_child==NULL;
}

/// case 7: siblings
void siblings(tree_t *t, int node_value){
    tree_t *pos=NULL;
    pos=search_node(t,node_value)->parent;
    if(pos==NULL){
      printf("\n");
      return;
    }
    pos=pos->first_child;
    while(pos!=NULL){
      if(pos->value!=node_value)
        printf("%d ",pos->value);
      pos=pos->next_sibling;
    }
    printf("\n");
}

/// case 8: depth
int depth(tree_t *t, int node_value){
  int count=0;
  tree_t *pos = search_node(t,node_value);
  while(pos->parent!=NULL){
    count+=1;
    pos=pos->parent;
  }
  return count;
}

/// case 9: print_path

void print_stack(stack_t *s){
  while(s!=NULL){
    printf("%d ",s->data);
    s=s->next;
  }
  printf("\n");
}  

void print_path(tree_t *t, int startnode_value, int endnode_value){
  tree_t *pos=search_node(t,endnode_value);
  while(pos!=NULL){
    s=push(s,pos->value);
    if(pos->value==startnode_value) break;
    pos=pos->parent;
  }
  print_stack(s);
  clearstack();
}

/// case 10: path_length
int path_length(tree_t *t, int startnode_value, int endnode_value){
  tree_t *pos=search_node(t,endnode_value);
  int count=1;
  while(pos->value!=startnode_value){
    count+=1;
    pos=pos->parent;
  }
  return count;  
}

/// case 11: ancestor
void ancestor(tree_t *t, int endnode_value){
  tree_t *pos=search_node(t,endnode_value);
  while(pos!=NULL){
    s=push(s,pos->value);
    pos=pos->parent;
  }
  print_stack(s);
  clearstack();
}

/// case 12: descendant
void descendant(tree_t *t, int node_value){
  tree_t *pos=search_node(t,node_value),*first=NULL;
  q = enqueue(q,node_value);
  while(q->front!=NULL){
    pos = search_node(t,q->front->data);
    q = dequeue(q);
    first = pos->first_child;
    while(first!=NULL){
      q = enqueue(q,first->value);
      first = first->next_sibling;
    }
  }
  printf("\n");
}

/// case 13: bfs
void bfs(tree_t *t){
  tree_t *pos=t,*first=NULL;
  q = enqueue(q,t->value);
  while(q->front!=NULL){
    pos = search_node(t,q->front->data);
    q = dequeue(q);
    first = pos->first_child;
    while(first!=NULL){
      q = enqueue(q,first->value);
      first = first->next_sibling;
    }
  }
  printf("\n");
  
}

/// case 14: dfs
void print_dfs(tree_t *t){
  if(t==NULL) 
    return;
  printf("%d ",t->value);
  print_dfs(t->first_child);
  print_dfs(t->next_sibling);
}
void dfs(tree_t *t){
  print_dfs(t);
  printf("\n");
}

/// case 15: print_tree
void print_tree(tree_t *t){
  int i;
  if(t==NULL) 
    return;
  for(i=0;i<depth(t,t->value)*4;i++){
    printf(" ");
  }
  printf("%d\n",t->value);
  print_tree(t->first_child);
  print_tree(t->next_sibling);

}

int main(void) {
  tree_t *t = NULL;
  int n, i, command;
  int parent, child, node, start, end;

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch(command) {
      case 1:
        scanf("%d %d", &parent, &child);
        t = attach(t, parent, child);
        break;
      case 2:
        scanf("%d", &node);
        t = detach(t, node);
        break;
      case 3:
        scanf("%d", &node);
        printf("%d\n", search(t, node));
        break;
      case 4:
        scanf("%d", &node);
        printf("%d\n", degree(t, node));
        break;
      case 5:
        scanf("%d", &node);
        printf("%d\n", is_root(t, node));
        break;
      case 6:
        scanf("%d", &node);
        printf("%d\n", is_leaf(t, node));
        break;
      case 7:
        scanf("%d", &node);
        siblings(t, node);
        break;
      case 8:
        scanf("%d", &node);
        printf("%d\n", depth(t, node));
        break;
      case 9:
        scanf("%d %d", &start, &end);
        print_path(t, start, end);
        break;
      case 10:
        scanf("%d %d", &start, &end);
        printf("%d\n", path_length(t, start, end));
        break;
      case 11:
        scanf("%d", &node);
        ancestor(t, node);
        break;
      case 12:
        scanf("%d", &node);
        descendant(t, node);
        break;
      case 13:
        bfs(t);
        break;
      case 14:
        dfs(t);
        break;
      case 15:
        print_tree(t);
        break;
    }
  }
  return 0;
}