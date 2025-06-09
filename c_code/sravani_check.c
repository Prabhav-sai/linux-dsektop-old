#include<stdio.h>
#include<stdlib.h>
struct Node {
    int value;
    int count;
    int index;
    struct Node *next;
};
typedef struct Node* NODE;
int compare(const void*a,const void *b){
    return ((int)a-(int)b);
}
NODE create(int value,int index){
    NODE new=(NODE)malloc(sizeof(struct Node));
    new->value=value;
    new->index=index;
    new->count=0;
    new->next=NULL;
    return new;
}
int hashfunction(int value,int table_size){
    return value%table_size;
}
//insertion
NODE search(NODE *hashTable,int searchvalue,int table_size) {
    int previous_int=searchvalue-1;
    int index = hashfunction(previous_int,table_size);
    NODE current = hashTable[index];

    while (current != NULL) {
        if (current->value==previous_int) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}
void insert(NODE hashTable[], int value, int e_index,int table_size) {
    int t_index = hashfunction(value,table_size);//we get table index
    NODE newNode = create(value,e_index);//element index
    NODE check_prev=search(hashTable,value,table_size);
    if(check_prev!=NULL){
        newNode->count=check_prev->count+1;
    }else{
        newNode->count=1;
    }
    //need to add condition if duplicates are present
    //update index and count
    if(hashTable[t_index]==NULL){
        hashTable[t_index]=newNode;
    }else{
        NODE current=hashTable[t_index];
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=newNode;
    }
}

//finding max
NODE maxcount(NODE hashTable[], int table_size) {
    NODE maxNode = NULL;

    for (int i = 0; i < table_size; i++) {
        NODE current = hashTable[i];

        while (current != NULL) {
            if (maxNode == NULL || current->count > maxNode->count) {
                maxNode = current;
            }
            current = current->next;
        }
    }

    return maxNode;
}
//to print index
int main(){
    int n;
    scanf("%d",&n);//covert n to prime later
    NODE table[n];
    for (int i = 0; i <n; i++) {
        table[i] = NULL;
    }
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        insert(table,arr[i],i,n);//replace n with primenumber
    }
    NODE max=maxcount(table,n);//replace n with primenumber
    // printf("%d\n",max->value);
    int arr_for_index[max->count];
    arr[0]=max->index;
    int value_index=(max->value);
    // printf("%d\n",table[hashfunction(value_index-2,n)]->index);
    for(int i=1;i<max->count;i++){
        NODE current=search(table,value_index,n);//replace n with primenumber
        arr[i]=current->index;
        value_index-=1;
    }
    for(int i=max->count-1;i>-1;i--){
        printf("%d ",arr[i]);
    }
    printf("\n");
}