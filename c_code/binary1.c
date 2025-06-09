#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int count=0;
    int c=n;
    while(c){
        c>>=1;
        count++;
    }
    for(int i=count-1;i+1;i--){
        int temp =n;
        temp >>=i;
        temp = temp&1;
        printf("%d",temp);
    }

    return 0;
}