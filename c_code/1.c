#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    printf("%d",n);
    while(2){
        if(n==1){
            break;
        }
        if(n%2==0){
            n=n/(2);
            printf(" %d",n);
        }
        else{
            n=(3)*n+1;
            printf(" %d",n);
        }
    }
    return 0;
}