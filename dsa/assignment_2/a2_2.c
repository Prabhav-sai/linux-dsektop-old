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
    long long int top,bottom;
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

void count_phones(tree t,long long int* ans){
    if(t==NULL) return;

    count_phones(t->left,ans);
    if(t->num==3) *ans +=1;
    count_phones(t->right,ans);

    return;
}

struct TrieNode {
    struct TrieNode *children[2];
    int count;
};

typedef struct TrieNode* Trie;

Trie create_trienode(){
    Trie node = (Trie)malloc(sizeof(struct TrieNode));
    node->children[0] = NULL;
    node->children[1] = NULL;
    node->count = 0;
    return node;
}

void insert_trienode(Trie t,int num){
    Trie node = t;
    for (int i = 20; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (node->children[bit]==NULL) {
            node->children[bit] = create_trienode();
        }
        node = node->children[bit];
        node->count++;
    }
}

int find_lower(Trie t, int num, int limit) {
    int ans = 0;
    Trie node = t;
    for (int i = 20; i >= 0 && node; i--) {
        int numbit = (num >> i) & 1;
        int limitBit = (limit >> i) & 1;
        if (limitBit==1) {
            if (node->children[numbit]) {
                ans += node->children[numbit]->count;
            }
            node = node->children[numbit ^ 1];
        } else {
            node = node->children[numbit];
        }
    }
    return ans;
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
    tree trees[300005];
    queue q= (queue)malloc(sizeof(struct queuenode));
    q->t=trees;
    q->bottom=0;
    q->top=0;
    long long int n;
    int num;
    int check =0;
    int* c = &check;
    scanf("%lld",&n);
    scanf("%d",&num);
    trees[0] = create_tree(num);
    enqueue(q,trees[0]);
    for(long long int i = 1;i<n;i++){
        scanf("%d",&num);
        if(num==0){
            if(check==1)q->bottom++;
            check = 1 - check;
            continue;
        }
        insert(q,num,c);
    }
    long long int left,right;
    scanf("%lld %lld",&left,&right);
    assign_phones(trees[0]);
    if(trees[0]->num==2) trees[0]->num=3;
    long long int answer=0;
    long long int* ans = &answer;
    count_phones(trees[0],ans);
    // print_in_order(trees[0]);
    long long int m = answer;
    Trie root = create_trienode();
    long long int result = 0;
    long long int count=0,prime_num=2;
    while (count < m) {
    if (isPrime(prime_num)) {
        result += find_lower(root, prime_num, right + 1) - find_lower(root, prime_num, left);
        insert_trienode(root, prime_num);
    count++;
    }
    prime_num++;
    }
    long long int a = m*(m-1);
    a = a/2;
    result = a - result;
    printf("%lld\n%lld",m,result);
    return 0;
}