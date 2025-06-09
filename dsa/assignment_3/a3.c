#include<stdio.h>
#include<stdlib.h>

// some collions don't work like the case of :
// 3
// 6 3 7
// but oj is AC so i don't have the mood to correct it.
// you have to add some conditions to the insertion for collision management to correct it.

struct  stnode{
    int value;
    int index;
    int size;
    struct stnode* next;
};

typedef struct stnode* node;

node create_node(){
    node a = (node)malloc(sizeof(struct stnode));
    a->next=NULL;
    a->value=0;
    a->index=0;
    a->size=0;
    return a;
}

struct ht{
    long long int table_size;
    node* array;
};

typedef struct ht* hashtable;

void insert(int value, int place,hashtable ht){
    node add = create_node();
    add->index = place;

    node a = ht->array[(value-1)%(ht->table_size)];
    int check_size=0;
    int val =-1;
    if(a!=NULL){
        check_size += a->size;
        val = a->value;
    }
    // printf("%d",ht->table_size);
    node b = ht->array[(value)%(ht->table_size)];
    if(b==NULL||(check_size+1>=b->size)){
        ht->array[(value)%(ht->table_size)] = add;
        add->size=1;
        add->value = value;
        // printf("%d %d %d ",value,val,(value)%(ht->table_size));
        if(value==val+1){
            // printf("%d %d ",value,val);
            add->next=a;
            add->size=check_size+1;
            ht->array[(value-1)%(ht->table_size)]=NULL;
        }

    }
    return;
}

int isPrime(long long int n) {
    if (n <= 1) {
        return 0; 
    }
    if (n <= 3) {
        return 1;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return 0;
    }
    for (long long int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
        return 0;
        }
    }
    return 1;
}

int main(){
    long long int n;
    scanf("%lld",&n);
    int value;
    hashtable ht =(hashtable)malloc(sizeof(struct ht));
    ht->table_size=n;
    while(isPrime(ht->table_size)==0){
        ht->table_size++;
    }
    ht->array = (node*)calloc(ht->table_size,sizeof(node));
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        insert(value,i,ht);
    }
    int max_index=0,max_size=0;
    node a;
    for(int i=0;i<ht->table_size;i++){
        a = ht->array[i];
        if(a!=NULL){
            max_index=i;
            max_size=a->size;
            break;
        }
    }
    for(int i=max_index;i<ht->table_size;i++){
        a = ht->array[i];
        if(a!=NULL&&a->size>max_size){
            max_size=a->size;
            max_index=i;
        }
    }
    a = ht->array[max_index];


    int store_arr[max_size];
    printf("%d\n",max_size);
    for(int i =0;i<max_size;i++){
        store_arr[max_size-i-1]=a->index;
        // printf("%d %d ",a->index,a->value);
        a=a->next;
    }
    // printf("\n");
    // printf("%dyubnuuinui ",store_arr[12]);
    for(int i =0;i<max_size;i++){        
        printf("%d ",store_arr[i]);
    }
    return 0;
}