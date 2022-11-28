#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEXTSIZE 21

typedef char* item_t;

typedef struct hash {
    item_t *table;
    int    size;
    int    hash_key;
} hash_t;

int F(int i){
    return (i+(i*i))/2;
}

unsigned int func(char *x, int index, int hash_key){
    if(index==0)
        return x[0];
    return hash_key*func(x,index-1,hash_key)+x[index];
}

unsigned int hash(hash_t *h, char *x){
    return func(x,strlen(x)-1,h->hash_key)%h->size;
}

hash_t *init_hashtable(int m, int hash_key){
    int i;
    hash_t *h = (hash_t*)malloc(sizeof(hash_t));
    h->table = (item_t*)malloc(sizeof(item_t)*m);
    h->size=m;
    h->hash_key=hash_key;
    for(i=0; i<m ;i++){
        h->table[i]=NULL;
    }
    return h;
}

void insert(hash_t *h, char *text ){
    unsigned int hashed = hash(h,text);
    int i=0;
    if(h->table[hashed]==NULL){
        h->table[hashed] = (char *)malloc(sizeof(char)*strlen(text));
        strcpy(h->table[hashed],text);
    }
    else{
        while(h->table[(hashed+F(i))%h->size]!=NULL)
            i+=1;
        h->table[(hashed+F(i))%h->size] = (char *)malloc(sizeof(char)*strlen(text));
        strcpy(h->table[(hashed+F(i))%h->size],text);
    }
}

int search(hash_t *h, char *text){
    unsigned int hashed = hash(h,text);
    int i=0,count=0;
    while(h->table[(hashed+F(i))%h->size]!=NULL || count>h->size){
        if(strcmp(h->table[(hashed+F(i))%h->size],text)==0)
            return (hashed+F(i))%h->size;
        i+=1;
        count+=1;
    }
    return -1;
}

int main(void){
    hash_t *hashtable =NULL;
    char    *text = NULL;
    int     m, n, i, hash_key;
    int     command;

    scanf("%d %d %d", &m, &n, &hash_key);
    hashtable = init_hashtable(m, hash_key);
    text = (char *)malloc(sizeof(char)*TEXTSIZE);

    for (i=0; i<n; i++){
        scanf("%d %s", &command, text);
        switch (command) {
            case 1:
                insert(hashtable, text);
                break;
            case 2:
                printf("%d\n",search(hashtable, text));
                break;
        }
    }
    return 0;
}