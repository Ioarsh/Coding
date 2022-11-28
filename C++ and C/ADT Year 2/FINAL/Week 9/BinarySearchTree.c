#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;  
} node_t;

typedef node_t bst_t;

// 1: insert
node_t *createNode(int data){
    node_t *tmp;
    tmp = (node_t*)malloc(sizeof(node_t));
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

bst_t *insert(bst_t *t, int data){
    if(t==NULL)
        return createNode(data);
    if(data<t->data)
        t->left = insert(t->left,data);
    else if(data>t->data)
        t->right = insert(t->right,data);
    return t;
}

// 3: find()
int find(bst_t *t, int data){
    int have=0;
    if(t==NULL)
        return 0;
    if(t->data==data)
        return 1;
    have=find(t->left,data);
    if(have!=0)
        return 1;
    return find(t->right,data);
}

// 4: find_min
bst_t *real_find_min(bst_t *t){
    if(t->left==NULL)
        return t;
    while(t->left!=NULL){
        t=t->left;
    }
    return t;
}

int find_min(bst_t *t){
    bst_t *min=NULL;
    min=real_find_min(t);
    return min->data;
}

// 5: find_max
int find_max(bst_t *t){
    if(t->right==NULL)
        return t->data;
    while(t->right!=NULL){
        t=t->right;
    }
    return t->data;
}

// 2: delete
bst_t *delete(bst_t *t, int data){
    bst_t *temp=NULL;
    if(t==NULL)
        return t;
    if(data < t->data)
        t->left = delete(t->left,data);
    else if(data>t->data)
        t->right = delete(t->right,data);
    else{
        if(t->left==NULL){
            temp = t->right;
            free(t);
            return temp;
        }
        else if(t->right==NULL){
            temp = t->left;
            free(t);
            return temp;
        }
        temp=real_find_min(t->right);
        t->data = temp->data;
        t->right = delete(t->right,t->data);
    }
    return t;
}


//Check
void trueprint_preorder(bst_t *t){
    if(t==NULL)
        return;
    trueprint_preorder(t->left);
    printf("%d ", t->data);
    trueprint_preorder(t->right);
}
void print_preorder(bst_t *t){
    trueprint_preorder(t);
    printf("\n");
}

int main(void){
    bst_t *t=NULL;
    int n, i;
    int command, data;

    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &command);
        switch (command) {
            case 1:
                scanf("%d", &data);
                t = insert(t, data);
                break;
            case 2:
                scanf("%d", &data);
                t = delete(t, data);
                break;
            case 3:
                scanf("%d", &data);
                printf("%d\n", find(t,data));
                break;
            case 4:
                printf("%d\n", find_min(t));
                break;
            case 5:
                printf("%d\n", find_max(t));
                break;
        }
    }
    return 0;
}