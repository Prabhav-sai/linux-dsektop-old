#include<stdio.h>
int factorial(int n){
    if(n==0){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int m = factorial(n);
    printf("%d\n",m);
    return 0;
}