#include<stdio.h>
int main(){
    int n,x,y;
    scanf("%d %d %d",&n,&x,&y);
    n= n-2;
    if(n==-1){
        printf("%d",x);
    }
    else{
    printf(" %d %d",x,y);
    }
    int temp;
    for(int i=0;i<n;i++){
        temp=y;
        y=y+x;
        printf(" %d",y);
        x=temp;
    }
    
    return 0;
}