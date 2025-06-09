#include<stdio.h>
#include<stdlib.h>

struct ststack{
    int* stackarray;
    int top;
};

typedef struct ststack* stack;

void push(stack stk,int num){
    stk->top +=1;
    stk->stackarray[stk->top]=num;
    return;
}

void pop(stack stk){
    stk->top -=2;
    return;
}

int top(stack stk){
    return stk->stackarray[stk->top];
}

int gcd(int a, int b){
    if(a==0)return b;
    if(b==0)return a;
    if(a>b) return gcd(a%b,b);
    else return gcd(a,b%a);
}

int main(){
    int n;
    scanf("%d",&n);
    int array[n];
    for(int i =0;i<n;i++){
        scanf("%d",&array[i]);
    }
    int stkarray[100000];
    stack stk = (stack)malloc(sizeof(struct ststack));
    stk->stackarray = stkarray;
    stk->top=-1;
    push(stk,array[0]);
    int gcd_num;
    int a,b;
    for(int i =1;i<n;i++){
        while(stk->top>0){ // >0 means there are atleast two element in array
            a = stk->stackarray[stk->top];
            b = stk->stackarray[stk->top-1];
            gcd_num = gcd(a,b);
            if(gcd_num>1){
                pop(stk);
                push(stk,(a*b)/gcd_num);
            }
            else{
                break;
            }
        }
        push(stk,array[i]);
    }
    printf("%d\n",stk->top+1);
    for(int i =0;i<=stk->top;i++){
        printf("%d ",stk->stackarray[i]);
    }
    return 0;

}