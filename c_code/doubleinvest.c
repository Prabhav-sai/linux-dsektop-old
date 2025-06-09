#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int count=0;
    while(n){
        if(n%2==0){
            n=n/2;
        }
        else{
            count++;
            n -=1;
        }
    }
    printf("%d",count);

    return 0;
}