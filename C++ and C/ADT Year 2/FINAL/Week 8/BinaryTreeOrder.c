#include<stdio.h>
#include<stdlib.h>
#include<week8.h>

#ifndef __bin_tree__
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
} node_t;

typedef node_t tree_t;
#endif

void trueprint_preorder(tree_t *t){
    if(t==NULL)
        return;
    printf("%d ", t->data);
    trueprint_preorder(t->left);
    trueprint_preorder(t->right);
}
void print_preorder(tree_t *t){
    trueprint_preorder(t);
    printf("\n");
}


void trueprint_postorder(tree_t *t){
    if(t==NULL)
        return;
    trueprint_postorder(t->left);
    trueprint_postorder(t->right);
    printf("%d ", t->data);
}
void print_postorder(tree_t *t){
    trueprint_postorder(t);
    printf("\n");
}

void trueprint_inorder(tree_t *t){
    if(t==NULL)
        return;
    trueprint_inorder(t->left);
    printf("%d ", t->data);
    trueprint_inorder(t->right);
}
void print_inorder(tree_t *t){
    trueprint_inorder(t);
    printf("\n");
}



int main(void){
    tree_t *t = NULL;
    int n, i;
    int parent, child;
    int branch; // 0 root, 1 left, 2 right

    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d %d %d", &parent, &child, &branch);
        t = attach(t, parent, child, branch);
    }
    print_preorder(t);
    print_postorder(t);
    print_inorder(t);


    return 0;
}
