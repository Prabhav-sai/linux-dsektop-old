#include<stdio.h>
#include<stdlib.h>

struct treenode{
    int val;
    struct treenode* left;
    struct treenode* right;
};

typedef struct treenode* tree;

struct queuenode{
    tree* t;
    int top,bottom;
};

typedef struct queuenode * queue;

void insertnode(queue q,int a){
    // q.t[]
}

int main(){
    tree* trees = (tree*)malloc(1000*sizeof(struct treenode));
    queue q; 
    q->t = trees;

    return 0;
}