#include<stdio.h>
#include<stdlib.h>

struct treenode{
    int num;
    struct treenode* right;
    struct treenode* left;
};

typedef struct treenode* tree;

struct queuenode{
    tree* t;
    int top,bottom;
};

typedef struct queuenode* queue;

void enqueue(queue q,tree a){
    q->t[q->top]=a;
    q->top+=1;
    return;
}

tree get_bottom(queue q){
    tree a = q->t[q->bottom];
    return a;
}

tree create_tree(int a){
    tree t = (tree)malloc(sizeof(struct treenode));
    t->num = a;
    t->left=NULL;
    t->right=NULL;
    return t;
}

void insert(queue q,int a,int* check){
    tree t = get_bottom(q);
    tree p = create_tree(a);
    if(*check == 0){
        t->left = p;
        enqueue(q,p);
        // printf("%d l\n",p->num);
        *check = 1;
        return;
    }
    if(*check == 1){
        t->right= p;
        enqueue(q,p);
        q->bottom+=1;
        // printf("%d r\n",p->num);
        *check = 0;
        return;
    }

}

void print_in_order(tree t){
    if(t==NULL) return;

    print_in_order(t->left);
    printf("%d",t->num);
    print_in_order(t->right);
    return;
}

int assign_phones(tree t){
    if(t==NULL) return 1;

    int l = assign_phones(t->left);
    int r = assign_phones(t->right);
    if(l>r) t->num = l;
    else t->num = r;
    t->num +=1;
    if(t->num==4) t->num = 1;
    if(l==2||r==2) t->num = 3;
    // printf("%d\n",t->num);
    return t->num;
}

void count_phones(tree t,int* ans){
    if(t==NULL) return;

    count_phones(t->left,ans);
    if(t->num==3) *ans +=1;
    count_phones(t->right,ans);

    return;
}

int main(){
    tree trees[300005];
    queue q= (queue)malloc(sizeof(struct queuenode));
    q->t=trees;
    q->bottom=0;
    q->top=0;
    int n,num;
    int check =0;
    int* c = &check;
    scanf("%d",&n);
    scanf("%d",&num);
    trees[0] = create_tree(num);
    enqueue(q,trees[0]);
    for(int i = 1;i<n;i++){
        scanf("%d",&num);
        if(num==0){
            if(check==1)q->bottom++;
            check = 1 - check;
            continue;
        }
        insert(q,num,c);
    }
    assign_phones(trees[0]);
    if(trees[0]->num==2) trees[0]->num=3;
    int answer=0;
    int* ans = &answer;
    count_phones(trees[0],ans);
    printf("%d\n",answer);
    // print_in_order(trees[0]);
    
    return 0;
}