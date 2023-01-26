#include <stdio.h>
#include <stdlib.h>
#include <week9.h>

#ifndef __avl_tree__
typedef struct node {
    int data;
    int height;
    struct node *left;
    struct node *right;
} node_t;

typedef node_t avl_t;
#endif

node_t *createNode(int data){
    node_t *tmp;
    tmp = (node_t*)malloc(sizeof(node_t));
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->height = 1;
    return tmp;
}

int max_side(int a, int b){
    if(b>a)
        return b;
    return a;
}

int height(avl_t *t){
    if(t==NULL)
        return 0;
    return t->height;
}

int check_balance(avl_t *t){
    if(t==NULL)
        return 0;
    return height(t->left) - height(t->right);
}

avl_t *right_rotate(avl_t *t){
    avl_t *left_node=t->left;
    avl_t *sub_node=left_node->right;

    left_node->right=t;
    t->left=sub_node;

    t->height = 1 + max_side(height(t->left),height(t->right));
    left_node->height = 1 + max_side(height(left_node->left),height(left_node->right));
    return left_node;
}

avl_t *left_rotate(avl_t *t){
    avl_t *right_node=t->right;
    avl_t *sub_node=right_node->left;

    right_node->left=t;
    t->right=sub_node;

    t->height = 1 + max_side(height(t->left),height(t->right));
    right_node->height = 1 + max_side(height(right_node->left),height(right_node->right));
    return right_node;
}

//Insert
avl_t *insert(avl_t *t, int data){
    if(t==NULL)
        return createNode(data);
    if(data<t->data)
        t->left = insert(t->left,data);
    else if(data>t->data)
        t->right = insert(t->right,data);
    t->height= 1+ max_side(height(t->left),height(t->right));


    int balance_value=check_balance(t);
    if(balance_value>1 && data<t->left->data)
        return right_rotate(t);
    if(balance_value<-1 && data>t->right->data)
        return left_rotate(t);
    if(balance_value>1 && data>t->left->data){
        t->left = left_rotate(t->left);
        return right_rotate(t);
    }
    if(balance_value<-1 && data<t->right->data){
        t->right = right_rotate(t->right);
        return left_rotate(t);
    }


    return t;
}


//Delete
avl_t *real_find_min(avl_t *t){
    if(t->left==NULL)
        return t;
    while(t->left!=NULL){
        t=t->left;
    }
    return t;
}

avl_t *delete(avl_t *t, int data){
    avl_t *temp=NULL;
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
        t->right =delete(t->right,t->data);
    }

    if(t==NULL)
        return t;

    t->height = 1 + max_side(height(t->left),height(t->right));
    
    int balance_value=check_balance(t);
    if(balance_value>1 && check_balance(t->left) >= 0)
        return right_rotate(t);
    if(balance_value<-1 && check_balance(t->right) <= 0)
        return left_rotate(t);
    if(balance_value>1 && check_balance(t->left) < 0){
        t->left = left_rotate(t->left);
        return right_rotate(t);
    }
    if(balance_value<-1 && check_balance(t->right) > 0){
        t->right = right_rotate(t->right);
        return left_rotate(t);
    }


    return t;
}


int main(void) {
    avl_t *t = NULL;
    int n, i;
    int command, data;

    scanf("%d", &n);
    for (i=0; i<n; i++){
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
                print_tree(t);
                break;
        }
    }
    return 0;
}