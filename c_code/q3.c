#include<stdio.h>
#include<stdlib.h>
typedef struct colornode{
    int color; // no of color
    struct colornode * next; //pointer to next node
}colornode;
typedef colornode* Linkedlist;
Linkedlist append(int colouradd,Linkedlist l){
    colornode* element = (colornode *)malloc(sizeof(colornode)); //creating a node using malloc to allote memory and store it over there instead of using local variable
    element ->color = colouradd; //filling the color of node
    element->next=NULL;
    Linkedlist temp =l;//using pointer for the first term
    if(l==NULL) return element;
    while(l->next!=NULL){
        l=l->next;
    }
    l->next=element;
    return temp;
}
void removeduplicates(Linkedlist l){
    Linkedlist temp=l;
    temp=temp->next;
    int check=l->color;
    while(temp!=NULL){
        if(check!=temp->color){
            l->next=temp;
            l=l->next;
            check=l->color;
        }
        if(temp==NULL) break;
        temp=temp->next;
    }
    l->next=NULL;
}
void printlist(Linkedlist l){
    while(l->next!=NULL){
        printf("%d -> ",l->color);
        l=l->next;
    }
    printf("%d\n",l->color);
    return;
}
int main(){
    printf("Input:\n");
    printf("Enter the number of colors in the list: ");
    int n;
    scanf("%d",&n);
    printf("Enter the colors: ");
    int list[n];
    Linkedlist colorlist=NULL;
    for(int i=0;i<n;i++){
        scanf("%d",&list[i]);
        colorlist = append(list[i],colorlist);
    }
    // printlist(colorlist);
    removeduplicates(colorlist);
    printf("Output:\n");
    printf("Modified Linked List: ");
    printlist(colorlist);

    return 0;
}