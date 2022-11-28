#include <stdio.h>
#include <stdlib.h>

typedef struct heap {
    int *data;
    int last_index;
} heap_t;

heap_t *init_heap(int m){
    heap_t *heap=(heap_t*)malloc(sizeof(heap_t));
    int *array = (int *)malloc(sizeof(int) * m);
    heap->data=array;
    heap->last_index= 0;
    int i=0;
    while(i!=m-1){
        array[i]=-1;
        i++;
    }
    return heap;
}

int parent(int i){
    if(i%2==0)
        return i/2-1;
    return i/2;
}
int child(int i){
    return (i+1)*2;
}
int find_index(int *arr,int data){
    int i=0;
    while(arr[i]!=data){
        i++;
    }
    return i;

}
void swap(int *x, int *y){
    int temp =*x;
    *x=*y;
    *y=temp;
}
void insert(heap_t *h, int data){
    int *arr=h->data;
    arr[h->last_index]=data;
    h->last_index++;
    int i=h->last_index-1;
    while(i!=0 && arr[i]>arr[parent(i)]){
        swap(&arr[i],&arr[parent(i)]);
        i = parent(i);
    }
}

void delete_max(heap_t *h){
    int *arr=h->data;
    if(arr[0]==-1)
        return;
    arr[0]=arr[h->last_index-1];
    arr[h->last_index-1]=-1;
    h->last_index--;
    int i=0;
    while(child(i)<h->last_index && (arr[i]<arr[child(i)] || arr[i]<arr[child(i)-1])){
        if(arr[i]<arr[child(i)-1]){
            swap(&arr[i],&arr[child(i)-1]);
            i=child(i)-1;
        }
        else{
            swap(&arr[i],&arr[child(i)]);
            i=child(i);
        }
    }
}

int find_max(heap_t *h){
    return h->data[0];
}

void update_key(heap_t *h, int old_key, int new_key){
    int *arr=h->data;
    int index=find_index(arr,old_key);
    arr[index]=new_key;
    int i=index;
    if(arr[i]>arr[parent(i)]){
        while(i!=0 && arr[i]>arr[parent(i)]){
        swap(&arr[i],&arr[parent(i)]);
        i = parent(i);
        }
    }
    else if((arr[i]<arr[child(i)] || arr[i]<arr[child(i)-1])){
        while(child(i)<h->last_index && (arr[i]<arr[child(i)] || arr[i]<arr[child(i)-1])){
        if(arr[i]<arr[child(i)-1]){
            swap(&arr[i],&arr[child(i)-1]);
            i=child(i)-1;
        }
        else{
            swap(&arr[i],&arr[child(i)]);
            i=child(i);
            }
        }

    }
    


}

void bfs(heap_t *h){
    int *arr=h->data , i=0;
    while(i!=h->last_index){
        printf("%d ",arr[i]);
        i++;
    }
    printf("\n");
}

int main(void) {
    heap_t *max_heap = NULL;
    int m, n, i;
    int command, data;
    int old_key, new_key;

    scanf("%d %d", &m, &n);
    max_heap = init_heap(m);
    for(i=0; i<n; i++){
        scanf("%d", &command);
        switch (command) {
            case 1:
                scanf("%d", &data);
                insert(max_heap, data);
                break;
            case 2:
                delete_max(max_heap);
                break;
            case 3:
                printf("%d\n", find_max(max_heap));
                break;
            case 4:
                scanf("%d %d", &old_key, &new_key);
                update_key(max_heap, old_key, new_key);
                break;
            case 5:
                bfs(max_heap);
                break;
        }
    }
    return 0;
}