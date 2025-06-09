#include<stdio.h>
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    if(a==b-1&&a!=3&&a!=6){
        printf("YES");
    }
    else{
        printf("NO");
    }
       
    return 0;
}