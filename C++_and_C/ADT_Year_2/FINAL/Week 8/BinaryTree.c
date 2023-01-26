#include <stdio.h>
#include <stdlib.h>
#include <week8.h> //จะแก้ใช้ "week8.h"

#ifndef __bin_tree__
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
} node_t;

typedef node_t tree_t;
#endif

int is_full(tree_t *t){
    if(t==NULL)
        return 1;
    if(t->left == NULL && t->right==NULL)
        return 1;
    if((t->left!=NULL)&&(t->right!=NULL))
        return is_full(t->left) && is_full(t->right);
    return 0;
}



int max_int(int a, int b){
    if(a>=b)
        return a;
    return b;
}
int depth(tree_t *t){
    if(t==NULL){
        return -1;
    }
    return max_int(depth(t->left),depth(t->right))+1;
}
int check_perfect(tree_t *t, int d, int level){
    if(t->left==NULL && t->right==NULL)
        return (d==level);
    if(t->left==NULL || t->right==NULL)
        return 0;
    return check_perfect(t->left,d,level+1) && check_perfect(t->right,d,level+1);
}
int is_perfect(tree_t *t){
    int d=depth(t);
    return check_perfect(t,d,0);
}


int count_nodes(tree_t *t){
    if(t==NULL)
        return 0;
    return(1+count_nodes(t->left)+count_nodes(t->right));
}
int check_complete(tree_t *t, int ind, int nodes_number){
    if(t==NULL)
        return 1;
    if(ind>=nodes_number)
        return 0;
    return (check_complete(t->left, 2*ind+1, nodes_number) && check_complete(t->right, 2*ind+2, nodes_number));
}
int is_complete(tree_t *t){
    int n=count_nodes(t);
    return check_complete(t,0,n);
}



int is_degenerate(tree_t *t){
    if(t==NULL)
        return 1;
    if(t->left!=NULL && t->right!=NULL)
        return 0;
    return is_degenerate(t->left) && is_degenerate(t->right);
}



char check_direction_skewed(tree_t *t){
    if(t->left==NULL)
        return 'R';
    return 'L';
}
int check_skewed(tree_t *t, char direction){
    if(t==NULL)
        return 1;
    if(t->left!=NULL && t->right!=NULL)
        return 0;
    if(t->left!=NULL && direction=='R')
        return 0;
    if(t->right!=NULL && direction=='L')
        return 0;
    return check_skewed(t->left,direction) && check_skewed(t->right,direction);
}
int is_skewed(tree_t *t){
    char direction=check_direction_skewed(t);
    return check_skewed(t,direction);
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
    printf("%d %d %d %d %d\n", is_full(t),is_perfect(t),is_complete(t),is_degenerate(t), is_skewed(t));

    return 0;
}