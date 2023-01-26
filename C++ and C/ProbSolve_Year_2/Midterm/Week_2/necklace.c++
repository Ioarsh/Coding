#include<iostream>
#include<list>
#include<cstdlib>
using namespace std;

typedef struct node{
    int data;
    struct node *before;
    struct node *next;
} node_t;

node_t *build(node_t *a,int n){
    node_t *h = (node_t *)malloc(sizeof (node_t));
    h->data=n;
    h->before=NULL;
    h->next=NULL;
    return h;
}

void show(node_t *a){
    while(a!=NULL){
        if(a->next==NULL) cout << a->data;
        else cout << a->data << ' ';
        a = a->next;
    }
    if(a==NULL) printf("\n");
}

int main(){
    int  n;
    cin >> n;
    node_t **bead_array=(node_t**)malloc(sizeof(node_t*)*n);
    for(int i=0;i<n;i++){
        bead_array[i]=build(bead_array[i],i+1);
    }
    for(int i=0;i<n-1;i++){
        int num,location;
        cin >> num >> location;
        if(bead_array[location-1]->next==NULL){
            bead_array[location-1]->next=bead_array[num-1];
            bead_array[num-1]->before=bead_array[location-1];
        }
        else{
            node_t *temp_next=bead_array[location-1]->next,*head=bead_array[location-1];
            bead_array[location-1]->next=bead_array[num-1];
            bead_array[num-1]->before=bead_array[location-1];
            while (head->next != NULL) {head=head->next;}
            head->next=temp_next;
            temp_next->before=head;
        }
    }
    node_t *head=bead_array[0];
    while(head->before!=NULL){
        head=head->before;
    }
    show(head);
    return 0;
}